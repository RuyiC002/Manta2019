using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO.Ports;

//Arduino's potentiometer control unity's lighting

public class AnalogInput : MonoBehaviour
{

    SerialPort sp = new SerialPort("/dev/cu.usbmodem14201", 9600);

    public string incomingData;
    public Light worldlight;
    //public float sensorValue;
    //loat timePassed = 0.0f;

    void Start()
    {
        sp.Open(); //Open the serialPort
        sp.ReadTimeout = 1; //Set it low, or unity might freeze.
     
    }


    void Update()
    {

       try{
            incomingData = sp.ReadLine();
            Debug.Log(incomingData);

            if (incomingData!="") {
            print ("called");
              lightMeUp(incomingData); 
              }
        }
       
        catch (System.Exception) { }
    
    }

    void lightMeUp(string sensorValue) {

        float f1 = float.Parse(sensorValue) / 100.0f;
        f1 = 1.0f - f1;

        worldlight = GetComponent<Light>();
        worldlight.intensity = f1;

    }



}
