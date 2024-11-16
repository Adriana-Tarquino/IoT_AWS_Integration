const Alexa = require('ask-sdk-core');
const AWS = require('aws-sdk');
const IotData = new AWS.IotData({ endpoint: 'aea4fbhz5gq4c-ats.iot.us-east-2.amazonaws.com' });

// Parámetros para actualizar el estado del ventilador en el shadow
const TurnFanOffParams = {
    thingName: 'Sensor_thing',
    payload: '{"state": {"desired": {"fan": 0}}}',
};

const TurnFanOnParams = {
    thingName: 'Sensor_thing',
    payload: '{"state": {"desired": {"fan": 1}}}',
};

const ShadowParams = {
    thingName: 'Sensor_thing',
};

// Función para obtener el estado actual del shadow
function getShadowPromise(params) {
    return new Promise((resolve, reject) => {
        IotData.getThingShadow(params, (err, data) => {
            if (err) {
                console.log(err, err.stack);
                reject(`Failed to get thing shadow ${err.message}`);
            } else {
                resolve(JSON.parse(data.payload));
            }
        });
    });
}

// Handler para el lanzamiento de la skill
const LaunchRequestHandler = {
    canHandle(handlerInput) {
        return Alexa.getRequestType(handlerInput.requestEnvelope) === 'LaunchRequest';
    },
    handle(handlerInput) {
        const speakOutput = 'Bienvenido a tu objeto inteligente AWS, tienes las opciones de encender, apagar y consultar el estado. ¿Qué deseas hacer?';

        return handlerInput.responseBuilder
            .speak(speakOutput)
            .reprompt(speakOutput)
            .getResponse();
    }
};

// Handler para encender el ventilador (LED)
const TurnOnIntentHandler = {
    canHandle(handlerInput) {
        return Alexa.getRequestType(handlerInput.requestEnvelope) === 'IntentRequest'
            && Alexa.getIntentName(handlerInput.requestEnvelope) === 'TurnOnIntent';
    },
    async handle(handlerInput) {
        let speakOutput = 'Solicitaste encender el ventilador.';
        try {
            await new Promise((resolve, reject) => {
                IotData.updateThingShadow(TurnFanOnParams, (err, data) => {
                    if (err) {
                        console.log(err);
                        reject(err);
                    } else {
                        resolve(data);
                    }
                });
            });
        } catch (error) {
            console.log(`Error al encender el ventilador: ${error}`);
            speakOutput = 'Hubo un problema al encender el ventilador.';
        }

        return handlerInput.responseBuilder
            .speak(speakOutput)
            .reprompt(speakOutput)
            .getResponse();
    }
};


// Handler para apagar el ventilador (LED)
const TurnOffIntentHandler = {
    canHandle(handlerInput) {
        return Alexa.getRequestType(handlerInput.requestEnvelope) === 'IntentRequest'
            && Alexa.getIntentName(handlerInput.requestEnvelope) === 'TurnOffIntent';
    },
    handle(handlerInput) {
        let speakOutput = 'Solicitaste apagar el ventilador!';
        IotData.updateThingShadow(TurnFanOffParams, function(err, data) {
            if (err) {
                console.log(err);
                speakOutput = 'Hubo un problema al apagar el ventilador.';
            }
        });

        return handlerInput.responseBuilder
            .speak(speakOutput)
            .reprompt(speakOutput)
            .getResponse();
    }
};

// Handler para consultar el estado del ventilador (LED)
const StateIntentHandler = {
    canHandle(handlerInput) {
        return Alexa.getRequestType(handlerInput.requestEnvelope) === 'IntentRequest'
            && Alexa.getIntentName(handlerInput.requestEnvelope) === 'StateIntent';
    },
    async handle(handlerInput) {
        let fanState = 'desconocido';
        try {
            const result = await getShadowPromise(ShadowParams);
            console.log('Shadow recibido:', JSON.stringify(result)); // Log para verificar el shadow completo
            if (result.state && result.state.desired && typeof result.state.desired.fan !== 'undefined') {
                fanState = result.state.desired.fan === 1 ? 'encendido' : 'apagado';
            }
        } catch (error) {
            console.log(`Error al consultar el estado del ventilador: ${error}`);
        }

        const speakOutput = `El ventilador está ${fanState}.`;
        return handlerInput.responseBuilder
            .speak(speakOutput)
            .reprompt(speakOutput)
            .getResponse();
    }
};


// Otros handlers de ejemplo
const HelpIntentHandler = {
    canHandle(handlerInput) {
        return Alexa.getRequestType(handlerInput.requestEnvelope) === 'IntentRequest'
            && Alexa.getIntentName(handlerInput.requestEnvelope) === 'AMAZON.HelpIntent';
    },
    handle(handlerInput) {
        const speakOutput = 'Puedes decir encender, apagar o consultar el estado del ventilador.';

        return handlerInput.responseBuilder
            .speak(speakOutput)
            .reprompt(speakOutput)
            .getResponse();
    }
};

const CancelAndStopIntentHandler = {
    canHandle(handlerInput) {
        return Alexa.getRequestType(handlerInput.requestEnvelope) === 'IntentRequest'
            && (Alexa.getIntentName(handlerInput.requestEnvelope) === 'AMAZON.CancelIntent'
                || Alexa.getIntentName(handlerInput.requestEnvelope) === 'AMAZON.StopIntent');
    },
    handle(handlerInput) {
        const speakOutput = '¡Adiós!';

        return handlerInput.responseBuilder
            .speak(speakOutput)
            .getResponse();
    }
};

// Otros handlers y configuraciones
exports.handler = Alexa.SkillBuilders.custom()
    .addRequestHandlers(
        LaunchRequestHandler,
        TurnOnIntentHandler,
        TurnOffIntentHandler,
        StateIntentHandler,
        HelpIntentHandler,
        CancelAndStopIntentHandler
    )
    .addErrorHandlers({
        canHandle() {
            return true;
        },
        handle(handlerInput, error) {
            console.log(`Error handled: ${error}`);
            return handlerInput.responseBuilder
                .speak('Hubo un error. Por favor, intenta de nuevo.')
                .getResponse();
        }
    })
    .lambda();
