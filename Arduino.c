#include<LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,2,1,0,4,5,6,7,3,POSITIVE);
float Ampere = 0;
float Power=0;
float Energy;
int i=0;
char Tx_Char[20]={""};
float Tx_Value=0;
int Tx_Val_Int=0;
float Tx_Val_Float;
int Tx_Val_Frc;

void setup()
{
	Serial.begin(9600);
	lcd.begin(16,2);
	pinMode(7,OUTPUT);
	pinMode(6,OUTPUT);
	digitalWrite(7,LOW);
}
void loop()
{
	//VOLTAGE DEFINING
	lcd.setCursor(0,0);
	lcd.print("230V");
	//CURRENT SENSING
	Ampere = GetCurrent();
	if(Ampere<0.16)
	{
		Ampere=0;
		digitalWrite(6,LOW);
		lcd.setCursor(9,0);
		lcd.print(Ampere);
		lcd.print("A ");
     }
	else if(Ampere>6.0)
	{
		digitalWrite(6,HIGH);
		lcd.setCursor(9,0);
		lcd.print(Ampere);
		lcd.print("A ");
		delay(8000);
	}
	else
	{
		digitalWrite(6,LOW);
		lcd.setCursor(9,0);
		lcd.print(Ampere);
		lcd.print("A ");
	}
	//POWER&ENERGY CALCULATIONS
	Power = 230*Ampere;
	Energy = Energy+(Power/3600);
	lcd.setCursor(0,1);
	lcd.print(Power);
	lcd.print("W ");
	if(i==0)
	{
		if(Energy >5)
		{
		i==1;
		digitalWrite(7,HIGH);
		delay(3000);
		digitalWrite(7,LOW);
		}
		lcd.setCursor(9,1);
		lcd.print(Energy);
		lcd.println("Wh ");
		Tx_Value = Energy;
		Tx_Val_Int = (int)Tx_Value;
		Tx_Val_Float = (abs(Tx_Value)-abs(Tx_Val_Int))*10;
		Tx_Val_Frc = (int)Tx_Val_Float;
		sprintf(Tx_Char,"%d.%d",Tx_Val_Int,Tx_Val_Frc);
		Serial.println(Tx_Char);
	}
	float GetCurrent()
	{
		float C_Voltage;
		float C_RMSVoltage;
		float AmpereResult;
		int C_ReadValue;
		int C_MaxValue = 0;
		int C_MinValue = 1024;
		uint32_t start_time = millis();
		while((millis() - start_time) < 1000)
		{
			C_ReadValue = analogRead(A1);
			if(C_ReadValue > C_MaxValue)
			{
				C_MaxValue = C_ReadValue;
			}
			if(C_ReadValue < C_MinValue)
			{
				C_MinValue = C_ReadValue;
			}
		}
		C_Voltage = (C_MaxValue - C_MinValue) * (5.0/1023.0);
		C_RMSVoltage = (C_Voltage / 2.0) * 0.707;
		AmpereResult = (C_RMSVoltage * 1000)/66;
		return AmpereResult;
	}
}
