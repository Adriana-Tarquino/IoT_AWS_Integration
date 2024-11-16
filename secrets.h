// el código para el archivo secrets.h:
#include <pgmspace.h>
 
#define SECRET
#define THINGNAME "SmartAir_Monitor"                       
 
const char WIFI_SSID[] = "LABO17";              
const char WIFI_PASSWORD[] = "catolica17";            
const char AWS_IOT_ENDPOINT[] = "aea4fbhz5gq4c-ats.iot.us-east-2.amazonaws.com";   
 
// Amazon Root CA 1
static const char AWS_CERT_CA[] PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----
MIIDQTCCAimgAwIBAgITBmyfz5m/jAo54vB4ikPmljZbyjANBgkqhkiG9w0BAQsF
ADA5MQswCQYDVQQGEwJVUzEPMA0GA1UEChMGQW1hem9uMRkwFwYDVQQDExBBbWF6
b24gUm9vdCBDQSAxMB4XDTE1MDUyNjAwMDAwMFoXDTM4MDExNzAwMDAwMFowOTEL
MAkGA1UEBhMCVVMxDzANBgNVBAoTBkFtYXpvbjEZMBcGA1UEAxMQQW1hem9uIFJv
b3QgQ0EgMTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBALJ4gHHKeNXj
ca9HgFB0fW7Y14h29Jlo91ghYPl0hAEvrAIthtOgQ3pOsqTQNroBvo3bSMgHFzZM
9O6II8c+6zf1tRn4SWiw3te5djgdYZ6k/oI2peVKVuRF4fn9tBb6dNqcmzU5L/qw
IFAGbHrQgLKm+a/sRxmPUDgH3KKHOVj4utWp+UhnMJbulHheb4mjUcAwhmahRWa6
VOujw5H5SNz/0egwLX0tdHA114gk957EWW67c4cX8jJGKLhD+rcdqsq08p8kDi1L
93FcXmn/6pUCyziKrlA4b9v7LWIbxcceVOF34GfID5yHI9Y/QCB/IIDEgEw+OyQm
jgSubJrIqg0CAwEAAaNCMEAwDwYDVR0TAQH/BAUwAwEB/zAOBgNVHQ8BAf8EBAMC
AYYwHQYDVR0OBBYEFIQYzIU07LwMlJQuCFmcx7IQTgoIMA0GCSqGSIb3DQEBCwUA
A4IBAQCY8jdaQZChGsV2USggNiMOruYou6r4lK5IpDB/G/wkjUu0yKGX9rbxenDI
U5PMCCjjmCXPI6T53iHTfIUJrU6adTrCC2qJeHZERxhlbI1Bjjt/msv0tadQ1wUs
N+gDS63pYaACbvXy8MWy7Vu33PqUXHeeE6V/Uq2V8viTO96LXFvKWlJbYK8U90vv
o/ufQJVtMVT8QtPHRh8jrdkPSHCa2XV4cdFyQzR1bldZwgJcJmApzyMZFo6IQ6XU
5MsI+yMRQ+hDKXJioaldXgjUkK642M4UwtBV8ob2xJNDd2ZhwLnoQdeXeGADbkpy
rqXRfboQnoZsG4q5WTP468SQvvG5
-----END CERTIFICATE-----
)EOF";
 
// Device Certificate                                              
static const char AWS_CERT_CRT[] PROGMEM = R"KEY(
-----BEGIN CERTIFICATE-----
MIIDWjCCAkKgAwIBAgIVAJsHjtMtKtEydtIcLC8Vr/4ll6e1MA0GCSqGSIb3DQEB
CwUAME0xSzBJBgNVBAsMQkFtYXpvbiBXZWIgU2VydmljZXMgTz1BbWF6b24uY29t
IEluYy4gTD1TZWF0dGxlIFNUPVdhc2hpbmd0b24gQz1VUzAeFw0yNDExMTQxODU4
MDdaFw00OTEyMzEyMzU5NTlaMB4xHDAaBgNVBAMME0FXUyBJb1QgQ2VydGlmaWNh
dGUwggEiMA0GCSqGSIb3DQEBAQUAA4IBDwAwggEKAoIBAQCxVOsc6RzkJ6Sn20rk
EdWTL8Y/rSIk6aZOC0rHbRs38+T1keIgrnzcI3HBtEOBXJOdwzh95JoQIkRLpbxi
3YsXn93qr8txpkM0B3N8dbHcqmqjHKsEo4i3fg+sjz7enDc9oJk4DKtsbisYm4W7
M1vNxZuZ7ec72wWPi3rA+nb4B9h20CYRsFdXDPrLHuiKVQnh3FRY1XXLtsIq5LMe
OXTRF8coW2SzOvwdcX6AfAv9Z2inzRTfNfCzqaga/4cx0pSUez3yUEmkTYJL3WgF
wTfJHqby6GzzakBgW8r3hwGUFDN+Jb6G5O8gK9vUXIM7ZaEj/vgxonv08c6ie3O0
n7FBAgMBAAGjYDBeMB8GA1UdIwQYMBaAFLu3U2mShqLqczpZYfeaT9kIcNTZMB0G
A1UdDgQWBBTrhI65GaBq80Vkf9WESeLhmghB6TAMBgNVHRMBAf8EAjAAMA4GA1Ud
DwEB/wQEAwIHgDANBgkqhkiG9w0BAQsFAAOCAQEAPRqiuZsnS8n21LCqudKjFGYD
24Fs0UA2q2MAsxi2HVVzq5L4N6knCRVEAbLvu2LbhHRkY78grbCBNAyG+lRDurjW
ruuFkq4qdAkvsM0UIYWhaJfln9Bm3iB10HmgA1Ybrl+gpsC+xwQbBRWnShKX+K2r
OD+X0al9qBu8ARFMzOAAW6HLIJxnIIxwUQTPyj9gyWvp1AG4wQ8Xk7KarWdUZ4mM
FzdleL0pbiI772Y9qDgOwkWqtn83qt3v7rlR7aTAy4dkRBly0RNKukfh0WRhD09J
eUsVryVtwlDSRLAujMH4FvlBLVbamufasLm4xe597jsV6+DqpDE4iX5IcNqeuQ==
-----END CERTIFICATE-----
)KEY";
 
// Device Private Key                                              
static const char AWS_CERT_PRIVATE[] PROGMEM = R"KEY(
-----BEGIN RSA PRIVATE KEY-----
MIIEpAIBAAKCAQEAsVTrHOkc5Cekp9tK5BHVky/GP60iJOmmTgtKx20bN/Pk9ZHi
IK583CNxwbRDgVyTncM4feSaECJES6W8Yt2LF5/d6q/LcaZDNAdzfHWx3Kpqoxyr
BKOIt34PrI8+3pw3PaCZOAyrbG4rGJuFuzNbzcWbme3nO9sFj4t6wPp2+AfYdtAm
EbBXVwz6yx7oilUJ4dxUWNV1y7bCKuSzHjl00RfHKFtkszr8HXF+gHwL/Wdop80U
3zXws6moGv+HMdKUlHs98lBJpE2CS91oBcE3yR6m8uhs82pAYFvK94cBlBQzfiW+
huTvICvb1FyDO2WhI/74MaJ79PHOontztJ+xQQIDAQABAoIBAErwyCt/mGYTGtKV
KiEYKFn7ZpyiXjubQlzZCNEemtIakDf3XsjQ9JNTp09lDuIsbXXOeqE5aqJG2PXf
JK3jUlS5it8TS7bLvLrQK039rxzCKC6mft+G/NAOxjD2mGsbOX0h0Z6OPCOmqy/L
CckC+1kKmaeDkqUI+mCfYVEMiBppAj6Q96e75UgTJEAibZg/ebpuLGn9RAecLsGX
t4hZatD+mYfYKwt087asg+CsZkF2SvrqMuMrh7aX1wwJfEyNgZnPb3s4ZbWs9/HN
R82xmr3nl1tDnn6LE7DmcCnvPxbePTPOGQ6W1r7lLkAMujJxRXJxaILfKYm4uZEe
e8aogQECgYEA2jPNytvaZo4vHgH8gkuwfGWeY+PYK4SaC1ttXKHy0DGsYHgTYbT1
UIhR4qplHi2HmWpDAq1I1pzcROeIopZXP5gBiXtcDsKBeLoMvs37JIdg3vydZyXW
ihZRBppMh52IzuO3TpzDoDhIfqaUK1sogLuEogNUNnWOD+wlAxiLbt0CgYEA0Ay0
EHHYxzDBpi74RXZG604G3ESv9hUfdxb8WxHJDdM+DJAsVEzNcTSyOC74QFrsj6LM
DQsLnWWh7eMni9ETYaMjsbRBkZBul46DX3dtjuYG8E9ev/pykFF9qzgc9m5ceUoF
nHXjcLhOBSKW2lLlgIDRDDIUeqgJ8cqsGQKtG7UCgYAvqGToS8CV6bQsz65BHxr6
8I75rkgGqT2kAWIPe2e3RUIrB87j5kw2PK/129WeE7+sKGNecE6aYURS4Gcda8y+
nQqo5oKizqTMo4YpHoAd6FumGHKglskW++zSjlzsueGpnl7pEqA/nEtpLiTqm0xr
YYmEgUmhY2eV3rPuyyuZGQKBgQCzhsK6jgLpn4D6zf0es3lvAt2YpQzR5FhKg2Mv
kqFTdL1OSfp2o++DiF1hbeZ6YftP1sMNXkKfh1u70xAE7l0zG3tplIof+en0jd1/
O6cmcAf8xgCU2KCTOD6gyML1QzY4008UPAYO9nsco0RZEL9Jq964D17smKQ8KQ9o
ZY7LIQKBgQC6Acpn/znWhb3VuqBUebI9iTcWpTkG8dXKL1glYD083iAlKXOcMJzY
M8p8PMeq/zkLCtYzp4svsE1eJybHOVuYI5ZNedZ5OGq6Yz11hTJxxppvBmMjas1B
T79hxY+P62ZJWdbkAsktNkBmN/kup696oKTI+xYCTg5WcVHQOsqpIA==
-----END RSA PRIVATE KEY-----
)KEY";