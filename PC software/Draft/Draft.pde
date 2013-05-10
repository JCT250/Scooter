/**
 * ControlP5 Slider. Horizontal and vertical sliders, 
 * with and without tick marks and snap-to-tick behavior.
 * by andreas schlegel, 2010
 */

/**
* ControlP5 Slider
*
* Horizontal and vertical sliders, 
* With and without tick marks and snap-to-tick behavior.
*
* find a list of public methods available for the Slider Controller
* at the bottom of this sketch.
*
* by Andreas Schlegel, 2012
* www.sojamo.de/libraries/controlp5
*
*/

import processing.serial.*;
import controlP5.*;

Serial port_one;  // Create object from Serial class
Serial port_two;
Serial port_three;

int val;        // Data received from the serial port

ControlP5 cp5;
int myColor = color(0,0,0);
Slider abc;
PFont fontA;

void setup() {
  size(500,400);
  noStroke();
  cp5 = new ControlP5(this);
  fontA = loadFont("Arial-BoldMT-48.vlw");
  textFont(fontA,15); 
  
 println(Serial.list());
 
  port_one = new Serial(this, Serial.list()[3], 115200);
  port_two = new Serial(this, Serial.list()[2], 115200);
 // port_three = new Serial(this, Serial.list()[0], 57600);
     
  // add a vertical slider
  cp5.addSlider("slider")
     .setPosition(20,40)
     .setSize(460,20)
     .setRange(0,255)
     .setValue(0)
     .setCaptionLabel("Throttle Position");
     ;
  
  // reposition the Label for controller 'slider'
  cp5.getController("slider").getValueLabel().align(ControlP5.RIGHT, ControlP5.BOTTOM_OUTSIDE).setPaddingX(0);
  cp5.getController("slider").getCaptionLabel().align(ControlP5.LEFT, ControlP5.BOTTOM_OUTSIDE).setPaddingX(0);
    
  cp5.addButton("speed1")
     .setValue(0)
     .setPosition(20,120)
     .setSize(100,20)
     .setCaptionLabel("Speed 1");
     ;
  // reposition the Label for controller 'speed1'
  cp5.getController("speed1").getCaptionLabel().align(ControlP5.CENTER, ControlP5.BOTTOM_OUTSIDE).setPaddingX(0);
  
  cp5.addButton("speed2")
     .setValue(0)
     .setPosition(140,120)
     .setSize(100,20)
     .setCaptionLabel("Speed 2");
     ;
  // reposition the Label for controller 'speed2'
  cp5.getController("speed2").getCaptionLabel().align(ControlP5.CENTER, ControlP5.BOTTOM_OUTSIDE).setPaddingX(0);
  
  cp5.addButton("speed3")
     .setValue(0)
     .setPosition(260,120)
     .setSize(100,20)
     .setCaptionLabel("Speed 3");
     ;
  // reposition the Label for controller 'speed3'
  cp5.getController("speed3").getCaptionLabel().align(ControlP5.CENTER, ControlP5.BOTTOM_OUTSIDE).setPaddingX(0);

  cp5.addButton("speed4")
     .setValue(0)
     .setPosition(380,120)
     .setSize(100,20)
     .setCaptionLabel("Speed 4");
     ;
  // reposition the Label for controller 'speed4'
  cp5.getController("speed4").getCaptionLabel().align(ControlP5.CENTER, ControlP5.BOTTOM_OUTSIDE).setPaddingX(0);  

  cp5.addButton("headlights")
     .setValue(0)
     .setPosition(20,170)
     .setSize(100,20)
     .setCaptionLabel("Headlights");
     ;
  // reposition the Label for controller 'speed1'
  cp5.getController("headlights").getCaptionLabel().align(ControlP5.CENTER, ControlP5.BOTTOM_OUTSIDE).setPaddingX(0);
  
  cp5.addButton("horn")
     .setValue(0)
     .setPosition(140,170)
     .setSize(100,20)
     .setCaptionLabel("Horn");
     ;
  // reposition the Label for controller 'speed2'
  cp5.getController("horn").getCaptionLabel().align(ControlP5.CENTER, ControlP5.BOTTOM_OUTSIDE).setPaddingX(0);
  
  cp5.addButton("left_indicator")
     .setValue(0)
     .setPosition(260,170)
     .setSize(100,20)
     .setCaptionLabel("Left Indicator");
     ;
  // reposition the Label for controller 'speed3'
  cp5.getController("left_indicator").getCaptionLabel().align(ControlP5.CENTER, ControlP5.BOTTOM_OUTSIDE).setPaddingX(0);

  cp5.addButton("right_indicator")
     .setValue(0)
     .setPosition(380,170)
     .setSize(100,20)
     .setCaptionLabel("Right Indicator");
     ;
  // reposition the Label for controller 'speed4'
  cp5.getController("right_indicator").getCaptionLabel().align(ControlP5.CENTER, ControlP5.BOTTOM_OUTSIDE).setPaddingX(0); 
  
  cp5.addButton("power_on")
     .setValue(0)
     .setPosition(20,220)
     .setSize(100,20)
     .setCaptionLabel("Power On");
     ;
  // reposition the Label for controller 'power'
  cp5.getController("power_on").getCaptionLabel().align(ControlP5.CENTER, ControlP5.BOTTOM_OUTSIDE).setPaddingX(0);  


  cp5.addButton("power_off")
     .setValue(0)
     .setPosition(140,220)
     .setSize(100,20)
     .setCaptionLabel("Power Off");
     ;
  // reposition the Label for controller 'power'
  cp5.getController("power_off").getCaptionLabel().align(ControlP5.CENTER, ControlP5.BOTTOM_OUTSIDE).setPaddingX(0); 
 
   cp5.addButton("remote_lock")
     .setValue(0)
     .setPosition(20,300)
     .setSize(100,20)
     .setCaptionLabel("Remote Lock");
     ;
    // reposition the Label for controller 'power'
    cp5.getController("remote_lock").getCaptionLabel().align(ControlP5.CENTER, ControlP5.BOTTOM_OUTSIDE).setPaddingX(0); 
 
   cp5.addButton("remote_unlock")
     .setValue(0)
     .setPosition(140,300)
     .setSize(100,20)
     .setCaptionLabel("Remote Unlock");
     ;
    // reposition the Label for controller 'power'
    cp5.getController("remote_unlock").getCaptionLabel().align(ControlP5.CENTER, ControlP5.BOTTOM_OUTSIDE).setPaddingX(0);  
}


void draw() {
  background(100);
  
  fill(255);  
  text("THROTTLE",20,30);
  
  fill(255);  
  text("MAIN CONTROLS",20,110);
  
  fill(255);
  text("GPS CONTROLS",20,290);
  
}

void loop(){
    
}

void slider(int theValue) {
  println("a slider event from throttle");
  port_one.write(theValue);
  port_one.write(0x0A);
}

void speed1(int theValue) {
  println("a button event from Speed 1");
  port_one.write("R1");
  port_one.write(0x0A);
  
}

void speed2(int theValue) {
  println("a button event from Speed 2");
  port_one.write("R2");
  port_one.write(0x0A);
}

void speed3(int theValue) {
  println("a button event from Speed 3");
  port_one.write("R3");
  port_one.write(0x0A);
}

void speed4(int theValue) {
  println("a button event from Speed 4");
  port_one.write("R4");
  port_one.write(0x0A);
}

void headlights(int theValue) {
  println("a button event from Headlights");
  port_one.write("R8");
  port_one.write(0x0A);
}

void horn(int theValue) {
  println("a button event from Horn");
  port_one.write("R7");
  port_one.write(0x0A);
}

void left_indicator (int theValue) {
  println("a button event from Left Indicator");
  port_one.write("R5");
  port_one.write(0x0A);
}

void right_indicator (int theValue) {
  println("a button event from Right Indicator");
  port_one.write("R6");
  port_one.write(0x0A);
}

void power_on(int theValue) {
  println("a button event from Power ON");
  port_one.write("RI");
  port_one.write(0x0A);
}

void power_off(int theValue) {
  println("a button event from Power OFF");
  port_one.write("RO");
  port_one.write(0x0A);
}

void remote_lock(int theValue) {
  println("a button event from remote_lock");
  port_two.write("0");
}

void remote_unlock(int theValue) {
  println("a button event from remote_unlock");
  port_two.write("1");
}

/**
* ControlP5 Slider
*
*
* find a list of public methods available for the Slider Controller
* at the bottom of this sketch.
*
* by Andreas Schlegel, 2012
* www.sojamo.de/libraries/controlp5
*
*/

/*
a list of all methods available for the Slider Controller
use ControlP5.printPublicMethodsFor(Slider.class);
to print the following list into the console.

You can find further details about class Slider in the javadoc.

Format:
ClassName : returnType methodName(parameter type)

controlP5.Slider : ArrayList getTickMarks() 
controlP5.Slider : Slider setColorTickMark(int) 
controlP5.Slider : Slider setHandleSize(int) 
controlP5.Slider : Slider setHeight(int) 
controlP5.Slider : Slider setMax(float) 
controlP5.Slider : Slider setMin(float) 
controlP5.Slider : Slider setNumberOfTickMarks(int) 
controlP5.Slider : Slider setRange(float, float) 
controlP5.Slider : Slider setScrollSensitivity(float) 
controlP5.Slider : Slider setSize(int, int) 
controlP5.Slider : Slider setSliderMode(int) 
controlP5.Slider : Slider setTriggerEvent(int) 
controlP5.Slider : Slider setValue(float) 
controlP5.Slider : Slider setWidth(int) 
controlP5.Slider : Slider showTickMarks(boolean) 
controlP5.Slider : Slider shuffle() 
controlP5.Slider : Slider snapToTickMarks(boolean) 
controlP5.Slider : Slider update() 
controlP5.Slider : TickMark getTickMark(int) 
controlP5.Slider : float getValue() 
controlP5.Slider : float getValuePosition() 
controlP5.Slider : int getDirection() 
controlP5.Slider : int getHandleSize() 
controlP5.Slider : int getNumberOfTickMarks() 
controlP5.Slider : int getSliderMode() 
controlP5.Slider : int getTriggerEvent() 
controlP5.Controller : CColor getColor() 
controlP5.Controller : ControlBehavior getBehavior() 
controlP5.Controller : ControlWindow getControlWindow() 
controlP5.Controller : ControlWindow getWindow() 
controlP5.Controller : ControllerProperty getProperty(String) 
controlP5.Controller : ControllerProperty getProperty(String, String) 
controlP5.Controller : Label getCaptionLabel() 
controlP5.Controller : Label getValueLabel() 
controlP5.Controller : List getControllerPlugList() 
controlP5.Controller : PImage setImage(PImage) 
controlP5.Controller : PImage setImage(PImage, int) 
controlP5.Controller : PVector getAbsolutePosition() 
controlP5.Controller : PVector getPosition() 
controlP5.Controller : Slider addCallback(CallbackListener) 
controlP5.Controller : Slider addListener(ControlListener) 
controlP5.Controller : Slider bringToFront() 
controlP5.Controller : Slider bringToFront(ControllerInterface) 
controlP5.Controller : Slider hide() 
controlP5.Controller : Slider linebreak() 
controlP5.Controller : Slider listen(boolean) 
controlP5.Controller : Slider lock() 
controlP5.Controller : Slider plugTo(Object) 
controlP5.Controller : Slider plugTo(Object, String) 
controlP5.Controller : Slider plugTo(Object[]) 
controlP5.Controller : Slider plugTo(Object[], String) 
controlP5.Controller : Slider registerProperty(String) 
controlP5.Controller : Slider registerProperty(String, String) 
controlP5.Controller : Slider registerTooltip(String) 
controlP5.Controller : Slider removeBehavior() 
controlP5.Controller : Slider removeCallback() 
controlP5.Controller : Slider removeCallback(CallbackListener) 
controlP5.Controller : Slider removeListener(ControlListener) 
controlP5.Controller : Slider removeProperty(String) 
controlP5.Controller : Slider removeProperty(String, String) 
controlP5.Controller : Slider setArrayValue(float[]) 
controlP5.Controller : Slider setArrayValue(int, float) 
controlP5.Controller : Slider setBehavior(ControlBehavior) 
controlP5.Controller : Slider setBroadcast(boolean) 
controlP5.Controller : Slider setCaptionLabel(String) 
controlP5.Controller : Slider setColor(CColor) 
controlP5.Controller : Slider setColorActive(int) 
controlP5.Controller : Slider setColorBackground(int) 
controlP5.Controller : Slider setColorCaptionLabel(int) 
controlP5.Controller : Slider setColorForeground(int) 
controlP5.Controller : Slider setColorValueLabel(int) 
controlP5.Controller : Slider setDecimalPrecision(int) 
controlP5.Controller : Slider setDefaultValue(float) 
controlP5.Controller : Slider setHeight(int) 
controlP5.Controller : Slider setId(int) 
controlP5.Controller : Slider setImages(PImage, PImage, PImage) 
controlP5.Controller : Slider setImages(PImage, PImage, PImage, PImage) 
controlP5.Controller : Slider setLabelVisible(boolean) 
controlP5.Controller : Slider setLock(boolean) 
controlP5.Controller : Slider setMax(float) 
controlP5.Controller : Slider setMin(float) 
controlP5.Controller : Slider setMouseOver(boolean) 
controlP5.Controller : Slider setMoveable(boolean) 
controlP5.Controller : Slider setPosition(PVector) 
controlP5.Controller : Slider setPosition(float, float) 
controlP5.Controller : Slider setSize(PImage) 
controlP5.Controller : Slider setSize(int, int) 
controlP5.Controller : Slider setStringValue(String) 
controlP5.Controller : Slider setUpdate(boolean) 
controlP5.Controller : Slider setValueLabel(String) 
controlP5.Controller : Slider setView(ControllerView) 
controlP5.Controller : Slider setVisible(boolean) 
controlP5.Controller : Slider setWidth(int) 
controlP5.Controller : Slider show() 
controlP5.Controller : Slider unlock() 
controlP5.Controller : Slider unplugFrom(Object) 
controlP5.Controller : Slider unplugFrom(Object[]) 
controlP5.Controller : Slider unregisterTooltip() 
controlP5.Controller : Slider update() 
controlP5.Controller : Slider updateSize() 
controlP5.Controller : String getAddress() 
controlP5.Controller : String getInfo() 
controlP5.Controller : String getName() 
controlP5.Controller : String getStringValue() 
controlP5.Controller : String toString() 
controlP5.Controller : Tab getTab() 
controlP5.Controller : boolean isActive() 
controlP5.Controller : boolean isBroadcast() 
controlP5.Controller : boolean isInside() 
controlP5.Controller : boolean isLabelVisible() 
controlP5.Controller : boolean isListening() 
controlP5.Controller : boolean isLock() 
controlP5.Controller : boolean isMouseOver() 
controlP5.Controller : boolean isMousePressed() 
controlP5.Controller : boolean isMoveable() 
controlP5.Controller : boolean isUpdate() 
controlP5.Controller : boolean isVisible() 
controlP5.Controller : float getArrayValue(int) 
controlP5.Controller : float getDefaultValue() 
controlP5.Controller : float getMax() 
controlP5.Controller : float getMin() 
controlP5.Controller : float getValue() 
controlP5.Controller : float[] getArrayValue() 
controlP5.Controller : int getDecimalPrecision() 
controlP5.Controller : int getHeight() 
controlP5.Controller : int getId() 
controlP5.Controller : int getWidth() 
controlP5.Controller : int listenerSize() 
controlP5.Controller : void remove() 
controlP5.Controller : void setView(ControllerView, int) 
java.lang.Object : String toString() 
java.lang.Object : boolean equals(Object) 


*/



