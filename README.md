# Arduino-EMO-robot (Still Under Construction. Now is 11 Oct 2024)
This is not EMO robot, but Arduino tries to make it the best it can

<p>This is under development. Please check full_jimmyrobot.ino file, I provide some features on it, such as:</p>
<ul>
  <li>Feeling angry</li>
  <li>Feeling happy</li>
  <li>feeling shocked</li>>
  <li>feeling confused</li>
  <li>and many</li>
</ul>

<p>I also use mpu6050 (GY-521) to detect if the robot lifted or shaked by user</p>

<p>Please check this code in INO file:<br />
<code>if (abs(ax) > 12000 || abs(ay) > 12000 || abs(az) < 1000) {</code></p>
<p>The values: 12000, 12000 and 1000 represents to aX, aY and aZ AXIS in mpu6050 module. You can change it based on the sensitivity of being lifted or shaked the best you want.</p>

<p>Again, this is NOT FINAL PROJECT, but you can develope it with your own concept. I will update it as soon as It is final and all is free for you.</p>

#ardujimmy #emo #robot #vector #arduino project
Dont forget to subscribe our channel at: https://www.youtube.com/@ardujimmy
