#include <EEPROM.h>

#include <ESP8266WebServer.h>
  // Comment this out to disable prints and save space
#include <ESP8266WiFi.h>






boolean invalida=false;
int in1 =D4; //LED do nodeMCU

int in2=D5;
int in3=D0;
int in4=D1;



int botao3=D3;

//Situação do Relê
boolean ligado1 = false;
boolean ligado2=false;
boolean ligado3=false;
boolean ligado4=false;
boolean controle=false;
boolean luzautomatica=false;
boolean internet=false;

int valor=A0;
int valor1=0;

// Estrutura de configuração da EEPROM

const char *password= "teste";
ESP8266WebServer server(80);




void handleRoot()
{
  String state = server.arg("funcao");
  if (state == "car") {
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
    digitalWrite(in3,HIGH);
    digitalWrite(in4,LOW);
    delay(500);
    digitalWrite(in1,LOW);
    digitalWrite(in2,LOW);
    digitalWrite(in3,LOW);
    digitalWrite(in4,LOW);

  
  }
  if (state=="cart"){
    digitalWrite(in2,HIGH);
    digitalWrite(in1,LOW);
    digitalWrite(in4,HIGH);
    digitalWrite(in3,LOW);
    delay(500);
    digitalWrite(in1,LOW);
    digitalWrite(in2,LOW);
    digitalWrite(in3,LOW);
    digitalWrite(in4,LOW);

   
  }
  if (state=="care"){
    digitalWrite(in1,HIGH);
    digitalWrite(in2,LOW);
    digitalWrite(in3,LOW);
    digitalWrite(in4,HIGH);
    delay(500);
    digitalWrite(in1,LOW);
    digitalWrite(in2,LOW);
    digitalWrite(in3,LOW);
    digitalWrite(in4,LOW);

   
  }
  if(state=="card"){
    digitalWrite(in1,LOW);
    digitalWrite(in2,HIGH);
    digitalWrite(in3,HIGH);
    digitalWrite(in4,LOW);
    delay(500);
    digitalWrite(in1,LOW);
    digitalWrite(in2,LOW);
    digitalWrite(in3,LOW);
    digitalWrite(in4,LOW);

   
  }
  // HTML da pagina principal
  String html = "<html><meta charset='UTF-8' language='pt-br'><title>Eletrônica e utilidades</title><body><center>";
  html+="<style type='text/css' media='all'>body{background-color:#D3D3D3;color:#2F4F4F;width: 90%;}";
  html+=".btn{background-color:#00008B;color:white;font-size:20px;font-family:Arial,Verdana}.btn:hover{background-color:white;color:#00008B;font-size:23px}";
  html+=".btn1{background-color:#B0C4DE;color:blue;font-size:20px;font-family:Arial,Verdana}.btn1:hover{background-color:#000080;color:white;font-size:23px}";
  html+="</style><h1>Eletrônica e utilidades</h1><div style='background-color:#D3D3D3;color:#00008B;;font-size:23px'><p>carrinho de controle</p>";
  html+="</div><div style='background-color:#191970;color:#191970;width:50%;height:6%;font-size:23px'>";
  html+="</div>";
html+="<div style='background-color:#00008B;color:white;height:60%;width:50%'>";
html +="<div style='background-color:#B0C4DE;color:#F8F8FF;height:60%;width:70%;margin: auto'><br><br><a href='/?funcao=car' class='btn1'>frente</a>";
html+="<br><br><a href='/?funcao=cart' class='btn1'>trás</a>";
 html +="<br><br><a href='/?funcao=care' class='btn1'>esquerda</a><br><br><a href='/?funcao=card' class='btn1'>direita</a>";
 
   html +="</div></div></center></body></html>";



  ;
  //Script JS para não abrir uma nova página Bootstrap
  html += "<script language='JavaScript' type='text/javascript'>";
  html += "var a=document.getElementsByTagName('a');";
  html += "for(var i=0;i<a.length;i++)";
  html += "{";
  html += "a[i].onclick=function()";
  html += "{";
  html += "window.location=this.getAttribute('href');";
  html += "return false";
  html += "}";
  html += "}";
  html += "</script>";
  //Fim da instrução
  html += "</center></div>";

  html += "</body></html>";
  // Enviando HTML para o servidor
  server.send(200, "text/html", html);
}



void setup()
{
  pinMode(in1,OUTPUT);
  pinMode(in2,OUTPUT);
  pinMode(botao3,INPUT);
  pinMode(in3,OUTPUT);
  pinMode(in4,OUTPUT);

 

  // Iniciando Serial
  Serial.begin(9600);

  

  // Iniciando EEPROM
  EEPROM.begin(512);


    
 


   
    WiFi.softAP("carrinho",password);//nome da rede e senha do AP
    IPAddress myIP = WiFi.softAPIP();


  // Apresenta dados da conexão
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println("192.168.4.1");
  Serial.print("IP address: ");
 



  // Atribuindo urls para funções
  // Quando não especificado método, uma função trata todos
  server.on("/", handleRoot);
 
 
  server.begin();
  Serial.println("HTTP server started");
  // Apenas informando que servidor iniciou
  Serial.println("HTTP server started");
}

void loop()
{// No loop só precisa dessa função
 server.handleClient();
  }
