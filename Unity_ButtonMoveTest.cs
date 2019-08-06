/*
 * To use 'System.IO.Ports;', you should change in Player settings
 * Build Settings - Player Settings - 'Player' tab
 * Configuration - Api Compatibility Level* ---> change to ‘NET 4.x’ 
 * Two buttons on Arduino for left & right can move the cube in unity accordingly
*/

using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO.Ports;

public class Move : MonoBehaviour
{

    public float speed; // Can enter the speed manually in the inspector.

    private float amountToMove;

    SerialPort sp = new SerialPort("/dev/cu.usbmodem14201", 9600); //initialize the serial port. If PC might be "COM3" as path

    void Start()
    {
        sp.Open(); //Open the serialPort
        sp.ReadTimeout = 1; //Set it low, or unity might freeze.
    }

    void Update()
    {

        amountToMove = speed * Time.deltaTime;

        if (sp.IsOpen) //Check if serial port is open
        {
            try
            {
                MoveObject(sp.ReadByte()); //use the function of moveObject
                Debug.Log(sp.ReadByte());  //print out the umber
            }
            catch(System.Exception) //catch the error if the serial port is not open
            {

            }

        }
    }

    void MoveObject(int Direction)  //Function to move the object
    {
        if (Direction ==1) // If first button on Arduino for left is pressed
        
        { 

            transform.Translate(Vector3.left * amountToMove, Space.World);

        }

        if(Direction == 2) //If second button on Arduino for right is pressed
       
         { 

            transform.Translate(Vector3.right * amountToMove, Space.World);
        
        }

    }
}
