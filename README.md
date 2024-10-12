# Arduino-EMO-robot (Still Under Construction. Now is 11 Oct 2024)
This is not EMO robot, but Arduino tries to make it the best it can

<h2>Concept</h2>
<p>This is under development. Please check full_jimmyrobot.ino file, I provide some features on it, such as:</p>
<ul>
  <li>Feeling angry</li>
  <li>Feeling happy</li>
  <li>feeling shocked</li>
  <li>feeling confused</li>
  <li>and many</li>
</ul>

<p>I also use mpu6050 (GY-521) to detect if the robot lifted or shaked by user</p>

<p>Please check this code in INO file:<br />
<code>if (abs(ax) > 12000 || abs(ay) > 12000 || abs(az) < 1000) {</code></p>
<p>The values: 12000, 12000 and 1000 represents to aX, aY and aZ AXIS in mpu6050 module. You can change it based on the sensitivity of being lifted or shaked the best you want.</p>

<h3>Wiring</h3>
<p>Please take notice of this following wiring:</p>
<ul>
  <li>SCL and SDA pins (Mpu6050 & LCD) are connected to A5 and A4 of arduino board pins</li>
  <li>Always power the LCD 0.96 Inch and the mpu6050 modules using 3.3v for STABLE power flow</li>
  <li>Power the arduino using 5v DC (in this concept)</li>
</ul>

<h3>Libraries</h3>
<p>In the list of files, I provided libraries needed to include before you upload your sketch:</p>
<ul>
<li>Adafruit_BusIO.zip</li>
<li>Adafruit_GFX.zip</li>
<li>Adafruit_SSD1306.zip</li>
<li>MPU6050.zip</li>
</ul>

<h3>STILL IN PROGRESS (SIP)</h3>
<p>This picture is not the same as the video uploaded in video short in my channel. I prefer using Infrared module to ultrasonic module. Why? Ultrasonic module looks bigger and I try to get small even tiny module to make it perfect as a final project.</p>
<p>I also remove two servos and bracket and change it to DC motor with gearbox N20 with 60 RPM to make the robot looks to the left and right.</p>
<img src="https://github.com/ArduJimmy/Arduino-EMO-robot/blob/main/emo-robot.jpeg" alt="Rmo Robot in Arduino" title="Arduino Emo Robot"/>
<p>Again, this is NOT FINAL PROJECT, but you can develope it with your own concept. I will update it as soon as It is final and all is free for you.</p>

#ardujimmy #emo #robot #vector #arduino project
Dont forget to subscribe our channel at: https://www.youtube.com/@ardujimmy
