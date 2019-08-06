using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO.Ports;

public class animController : MonoBehaviour

{

    public Animator anim;

    //public float speed; // Can enter the speed manually in the inspector.
    //private float amountToMove;

    SerialPort sp = new SerialPort("/dev/cu.usbmodem14201", 9600); //initialize the serial port. If PC might be "COM3" as path

    // Start is called before the first frame update
    void Start()
    {
        anim = GetComponent<Animator>();

        sp.Open(); //Open the serialPort
        sp.ReadTimeout = 1; //Set it low, or unity might freeze.
    }

    // Update is called once per frame
    void Update()
    {

        //amountToMove = speed * Time.deltaTime;

        if (sp.IsOpen) //Check if serial port is open
        {
            try
            {
                MoveObject(sp.ReadByte()); //use the function of moveObject
                Debug.Log(sp.ReadByte());  //print out the number
            }
            catch (System.Exception) //catch the error if the serial port is not open
            {

           }
        }
    }

    void MoveObject(int Direction)  //Function to move the object

    {
        if (Direction == 1) // If first button on Arduino for left is pressed

        {

            anim.speed = 2;

        }

        if (Direction == 2) //If second button on Arduino for right is pressed

        {

            anim.speed = 0;

        }

    }
}
