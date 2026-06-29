# Devlogs

Hi! Welcome to my project journal! Before you take a peek, you may realize that the commits do not match the logs. That is because this is literally my first time using Github and I didn't really know how to do a journal for devlogs until I was gonna ship :P
If you're a reviewer reviewing my project and you really need proof of the devlogs, I wrote quick summaries under each of my timelapses in Lapse, which is also what my devlogs will be based on. If you need anything from me to clear things up, please let me know in any way. I check Slack very often. Sorry for the inconvenience! Thank you for all your hard work :)

NOTE: If you are checking my project out from Stardance, the reason why I have this Journal.md is because this project was started in Horizons. I had to keep my devlogs here because there was no devlog feature on the website. I stopped updating this journal when I moved over to Stardance, and I wrote the rest of my devlogs there. Thanks for the understanding!

# Devlog 1
1h 0min 27sec Logged

I started working on my Upcycler project today! I need to make a full 3D model as a plan, so I found some files online of a motorized mechanism that pulls the PET in a PET puller. I imported them into my project, but I discovered that they need 608 2RS bearings, M8-1.25 60mm screws, and M8-1.25 hex nuts to be fully put together. I found the dimensions of those parts online and modeled them myself! Afterwards, I brought all the part studios into an assembly and put together the first model of the body (you can find models in branch First-CADS). However, I still need to greatly adapt the puller mechanism to use 28BYJ-48 stepper motors instead of expensive 12V 3RPM DC motors. I started that today by calculating the grams of force per centimeter sqaured of each motor. My motor was approximately 20x weaker than theirs. To compensate for friction, bending of the materials, and the fact that the spool's axle has only one attachment point, I estimated the need for a 30:1 ratio. I modeled the driven gear as large as I could, but my math still does not see my mechansim working. I'll need to improvise a geartrain for everything to work. 

![Picture of Big Gear](Images/BGDevlog1.png)
![Picture of Upcycler](Images/Devlog1.png) 

# Devlog 2
1h 1min 12sec Logged

I worked on the geartrain for my Upcycler! I finished modeling the big gear to fit the spool and the axle, and I'm getting started on the other gears. I've decided to incorporate four gears: the driver gear will be connected to the 28BYJ-48 stepper motor, the driven gear will be above that (at a 24:7 ratio), and the driven gear will be on the same axle the small gear, which will drive the big gear (at a 61:7 ratio). That should result it a roughly 30:1 ratio. Of course, to fit the new axles and gears, I had to change the body of the puller a lot. I removed the mounting holes meant for the original motor, and I made new slots for new bearings. You can find the files in the 2nd-CADs branch.

![Another Picture of Big Gear](Images/BGDevlog2.png) 
![Second Picture of Upcycler](Images/Devlog2.png) 

# Devlog 3
1h 4min 57sec Logged

I finished adapting the body of the puller! I added all the necessary bearing slots, I added attachment points for the 28BYJ-48 stepper, and I trimmed a bit off the stud to save filament, save time, and make installment easier. I modeled all three other gears, and I'll put the assembly together soon. however, I decided that I wanted two attachment points for the spool's axle. First, I had to make the other end of the spool capable of taking an axle. I modeled a spool cap by using the same inner ring I used for the big gear. I will be able to add that to the other end of the printed spool. That means I'll need to model a shorter body next, as the second attachment point doesn't need a motor and geartrain, but it does need support. 

![Picture of Spool Cap](Images/Devlog3A.png)
![Picture of adapted body](Images/Devlog3B.png)

# Devlog 4
1h 7min 10sec Logged

First, I modeled the short body. I basically just copied the normal body and cut off the top. I used a circle centered on the axle and tangent to the body's sides to mark the roof. Afterwards, I modeled the legs of the Upcycler. I had to match dimensions I estimated in real life. I'm planning to secure them to the wooden base using #8-32 screws. Finally, I started putting everything together in the assembly again. So much has changed since I did this the first time! I had to redo a bunch of stuff. Everything fits perfectly, as per my calculations! I need to move on to modeling the rest of the Upcycler next: the puller is just one of the biggest parts. You can find the CAD files in the 3rd-CADs branch. 

![Picture of short body](Images/Devlog4A.png)
![Picture of Devlog 4 Assembly](Images/Devlog4B.png)

# Devlog 5
1h 2min 49sec Logged

I grinded out models of all the screws that I'll be using! I couldn't find any #8-32 screw models online that were in parasolid format, so I decided to model them myself! I modeled the #8-32 1.5in, 1in, and 0.75in screws. I also modeled a 1in #6-32 screw. I added them all to the assembly and put them all in place! Afterwards, I added the base to the assembly and added holes to it for the #8-32 screws to secure the legs. Things are really coming together!

![Picture of #8-32 1.5in screw model](Images/Devlog5A.png)
![Picture of assembly with screws](Images/Devlog5B.png)

# Devlog 6
1h 4min 45sec Logged

I added more holes to the base for attaching the puller. The plan is to make the holes around 3/16in wide in diameter in real life, larger than the #8-32 1in screws' diameters, so that there will be room for error while drilling. Then, the screws (and the bodies they wil be securing) will be secured using #8-32 hex nuts. I added the legs to the assembly and attached them to the base as planned. Finally, I found 3D models of a few of the electrical components I used online and added them to the assembly. I don't like them very much, as they are not parasoilds that Onshape can render easily, but I suppose they'll do for now. I think I'll just make my own models in the future. 

![A picture of adding holes to the base](Images/Devlog6A.png)
![A picture of the assembly with legs and an imported ULN2003 model](Images/Devlog6B.png)

# Devlog 7
1h 0min 22sec Logged 

I found more files for more of the electronics I used online. One of them, the breadboard, was able to be rendered by Onshape, and it looks fine. The other, the OLED, was not able to be rendered by Onshape, and it is another janky-looking part. I still added them to the assembly. I wanted to add the WAGOs next, but I also wanted to avoid weird files, so I modeled the WAGOs myself. I found the dimensions online and even added fillets to make them look more realistic. I think that I'm pretty good at that, so I think I'll model more parts. In the meantime, the assembly is looking more and more complete every Devlog! You can find the files in the 4th-CADs branch. 

![A picture of a 2-way WAGO I modeled](Images/Devlog7A.png)
![A picture of the assembly with all the parts thus far](Images/Devlog7B.png)

# Devlog 8
2h 53min 17sec Logged 

Oh, boy! I really locked in for this CAD session! I modeled the rest of the components, by myself!I modeled the relay, the 12V-5V buck converter, the l-bracket, the CR-10 heat block, and I turned the assembly into a simulation! The l-bracket and CR-10 heat block were easy to model, because I just had search up their dimensions online and translate that into a part studio in Onshape. The relay and 12V-5V buck converter were harder. I had them in real life, so I used a digital caliper to measure the individual parts and model them in Onshape to the best of my ability. I got details like filets and chamfers, and I added extrude removes for USB ports, wire ports, and screw ports. Afterwards, I added all the parts to the assembly, and I finished putting everything together! That wasn't it, though! To see how it would really work, I added gear relationships to the revolve mates of the gears, and I saw Onshape simulating the Upcycler running! I'm ready to build the Upcycler now!

![A picture of the 12V-5V buck Converter](Images/Devlog8A.png)
![A picture of adding simulation to the gears](Images/Devlog8B.png)
![A picture of the finished assembly](Images/Devlog8C.png)

# Devlog 9
1h 2min 34sec Logged

This was my first building session! First, I drilled four holes at the corners of the wooden base I got to attach the legs. I had printed the legs out beforehand, so I just had to screw them on. Then, I put together the short body. I inserted the bearings, I threaded the M8-1.25 60mm screw, I screwed on a nut, I screwed on the spool cap, and I screwed on a second nut. Afterwards, I put together the axle of the main body. I repeated the same process as the short body, but I used the big gear instead of the spool cap. I then secured the spool body onto the big gear using four #6-32 1in screws. Things are going well so far!

![A picture of the assembled short body, short of the second nut](Images/Devlog9A.png)
![A picture of securing the spool body to the big gear on the main body](Images/Devlog9B.png)

# Devlog 10
1h 6min 37sec Logged

I continued building the Upcycler! I screwed the driven gear and the small gear together using a #8-32 1.5in screw, and after attaching a nut, they can no longer spin independently. However, that was before I screwed the base screws onto the body, and the driven gear got in the way of me doing that, so I had to undo my work, screw in the base screws, and put them back on again. In other news, I attached the spool cap (and the short body) onto the other side of the spool body, making our puller assembly complete! Our 28BYJ-48 stepper motor is ready to go, it just needs the electrical components now, which is what we will be working on next!

![A picture of me joining the driven gear and the small gear using a #8-32 1.5in screw](Images/Devlog10A.png)
![A picture of me attaching the spool cap and the short body onto the other end of the spool body](Images/Devlog10B.png)

# Devlog 11
1h 45min 52sec Logged

I finsihed building the Upcycler's electrical system today! I drilled the holes in the base for the bodies of the puller assembly, and I slid the bodies into the holes via their screws. On the belly side of the base, I used #8-32 hex nuts to secure the bodies in place. I hot-glued all of the elecrical components in place, and I got all of the wiring done, shy of the heat block. The heating component is the last part I need to finish. In other news, I found the relay I wanted to use too big, so I replaced it with a MOSFET module. I'll redo the CAD on that part next. 

![A picture of the underside of the Upcycler, with 3 of the 4 hex nuts installed for the screws of the bodies](Images/Devlog11A.png)
![A picture of me hot-gluing the Arduino Uno in place](Images/Devlog11B.png)
![A picture of the up-to-date Upcycler!](Images/Devlog11C.png)

# Devlog 12
0h 37min 57sec Logged

I updated the assembly to have the MOSFET module instead of the relay! I modeled the MOSFET that I used, and I used it to replace the relay in the assembly. This fit a lot easier now. The updated CAD files are in 6th-CADs (branch).

![A picture of the MOSFET module I modeled](Images/Devlog12A.png)
![A picture of the up-to-date CAD assembly](Images/Devlog12B.png)

# Devlog 13
49min 20sec Logged

Hi! This is the first devlog for my Upcycler project on Stardance! I started this project in Horizons, but I decided to move over to Stardance after 15 hours of work after seeing how Stardance is more hardware-oriented. To recap the work I did in Horizons, I found a set of 3D files for a body of a Petamentor and adapted them to use a 28BYJ-48 stepper motor. I chose a lot of parts to heat up 7mm strips of PET and control the motor, modeled them on Onshape, bought them in real life, and assembled part of the Upcycler. For this first devlog in Stardance, I started assembling the heating component. I drilled holes in the base to fit the L-bracket that will hold the heat block, and I attached two two-way WAGOs to incorporate a thermistor to track the temperature of the heat block. I added all of the electrical components the thermistor will need. Of course, there is a lot more to my journey than I wrote here. Check out my Github repo to see the entire process (including my work in Horizons!)

![A picture of the in-progress Upcycler](https://stardance.hackclub.com/rails/active_storage/representations/proxy/eyJfcmFpbHMiOnsiZGF0YSI6NzY5NzcsInB1ciI6ImJsb2JfaWQifX0=--43f8bc8eaad5d601da5c42e0e636f3caf18ae653/eyJfcmFpbHMiOnsiZGF0YSI6eyJmb3JtYXQiOiJ3ZWJwIiwicmVzaXplX3RvX2xpbWl0IjpbMTYwMCw5MDBdLCJzYXZlciI6eyJzdHJpcCI6dHJ1ZSwicXVhbGl0eSI6NzV9fSwicHVyIjoidmFyaWF0aW9uIn19--3bc8a2c9d65e3b087c0c0b37dcfb642bb247bc73/IMG_0086.jpg)

# Devlog 14
38min Logged 

I finished building the heating component for the Upcycler today! I connected the ceramic heater to the MOSFET module, and I inserted both the heater and the thermistor into the heat block. I secured the heat block onto the L-Bracket using an adapted 0.4mm nozzle (I expanded it to 1/16in). The entire physical build for the Upcycler is complete! I will work on an improved code now!

![A picture of the completed Upcycler V2](https://stardance.hackclub.com/rails/active_storage/representations/proxy/eyJfcmFpbHMiOnsiZGF0YSI6Nzg5MzgsInB1ciI6ImJsb2JfaWQifX0=--ed743a26b6d19188c689d22d1dcb9007f76b7217/eyJfcmFpbHMiOnsiZGF0YSI6eyJmb3JtYXQiOiJ3ZWJwIiwicmVzaXplX3RvX2xpbWl0IjpbMTYwMCw5MDBdLCJzYXZlciI6eyJzdHJpcCI6dHJ1ZSwicXVhbGl0eSI6NzV9fSwicHVyIjoidmFyaWF0aW9uIn19--3bc8a2c9d65e3b087c0c0b37dcfb642bb247bc73/WIN_20260624_13_15_01_Pro.jpg)

# Devlog 15
1h 19min 45sec Logged

I finished updating the code for my Upcycler project! I already knew the jist of the things I needed from the AI-generated code I used to use, so I was able to finish everything in just one session.
The biggest change I made was adding a safety feature for the heating component. If the 6x20mm 12V 40W ceramic heating components I use get too hot, they pose a fire hazard, not to mention the fact that they can damage themselves, the parts around them, and the electrical components they connect to. They can only go up to 350 degrees Celsius before those things start to happen, and my old code allowed operation up to 360 degrees, so I updated the max to be 340 (meaning there’s a 10 degree margin of safety).

I also made a few quality of life changes in the UI.

I listed the current code version and model next to the title
I labeled the temperature readings in both the main menu and the operating menu with “C” (to clarify that the readings are in degrees Celsius)
I more clearly labeled the temperature readings in both the main menu and the operating menu as “Current_Temp” to avoid confusion
-I more clearly labeled the target temperature readings in both the main menu and the operating menu as “Target_Temp” to avoid confusion
I more clearly labeled the motor reading in the main menu as “Motor_Status” to avoid confusion
I more clearly labeled the speed reading in the main menu as “Steps/s” to avoid confusion
I reset the default steps per second to 150 to make usage more convenient
I reset the default temperature to 210 degrees Celsius to make usage more convenient
I added notes to the .ino file to guide users when reconstructing the Upcycler
That was all for the code! I can get back to the good hardware stuff now!

![An image of the Upcycler's OLED in its menu state](https://stardance.hackclub.com/rails/active_storage/representations/proxy/eyJfcmFpbHMiOnsiZGF0YSI6Nzk2MjIsInB1ciI6ImJsb2JfaWQifX0=--c97f3ad7eb512e004b6bbd09c4bd8e30ebc963b0/eyJfcmFpbHMiOnsiZGF0YSI6eyJmb3JtYXQiOiJ3ZWJwIiwicmVzaXplX3RvX2xpbWl0IjpbMTYwMCw5MDBdLCJzYXZlciI6eyJzdHJpcCI6dHJ1ZSwicXVhbGl0eSI6NzV9fSwicHVyIjoidmFyaWF0aW9uIn19--3bc8a2c9d65e3b087c0c0b37dcfb642bb247bc73/WIN_20260624_18_43_55_Pro.jpg)

# Devlog 16
47min 55sec Logged

I finished updating the CAD files for my Upcycler project today!

I fixed the problem of the bodies’ legs always cracking when you screw in their screws too tight. I did that by creating notches for their caps to settle in. This should also keep the legs sturdy over long-term wear.

Another problem I’ve had for a while was the bodies not lining up in the assemblies for some reason. I found the root of that problem while improving the legs. The legs were actually slightly offset on the bodies on the x-axis for some reason. I was able to fix that easily when reattaching the legs. Redoing the base to fit this change was more difficult, but a bit of brute force did the trick ;)

I’ll be printing these new parts out now. After replacing the old ones, the Upcycler V3 will be done!

![An image of the improved Short Leg](https://stardance.hackclub.com/rails/active_storage/representations/proxy/eyJfcmFpbHMiOnsiZGF0YSI6ODEzNjAsInB1ciI6ImJsb2JfaWQifX0=--97563ff5b964e705485a2eb1d67595e5d348db42/eyJfcmFpbHMiOnsiZGF0YSI6eyJmb3JtYXQiOiJ3ZWJwIiwicmVzaXplX3RvX2xpbWl0IjpbMTYwMCw5MDBdLCJzYXZlciI6eyJzdHJpcCI6dHJ1ZSwicXVhbGl0eSI6NzV9fSwicHVyIjoidmFyaWF0aW9uIn19--3bc8a2c9d65e3b087c0c0b37dcfb642bb247bc73/SDDV1.png)

# Devlog 17
1h 2min Logged

I finished the Upcycler V3 today! YAY!

I started printing the new models I made yesterday this morning. There were only two parts (the main body and the short body) but they still took all day lol :p: .

I also had to fix my 3D printer in between the two prints because it started leaking filament out of its throat and the melted filament dripped onto the prints and left these weird brown streaks.

After the parts were finished I replaced the old parts with the new. That took a whole hour because all the smaller parts are built onto these two biggest parts, and I use very fine mechanical screws (which take a long time to install/remove). The new parts work really well, tho! They solved the old problem of the bases cracking when you screwed in their screws too tight.

Anyway, this is it! I tested the Upcycler V3 and it worked well! Just like its previous versions, you cut PET filament from 2L soda bottles into 7mm wide strips and feed them through the nozzle at 210 C at 150 steps/s.

Check out my GitHub repo if you want to build this yourself! YIPPIEEEEE!

![An image of the completed Upcycler V3](https://stardance.hackclub.com/rails/active_storage/representations/proxy/eyJfcmFpbHMiOnsiZGF0YSI6ODU0MjUsInB1ciI6ImJsb2JfaWQifX0=--ac28fe033d202cda3b777461665f6a5c20314696/eyJfcmFpbHMiOnsiZGF0YSI6eyJmb3JtYXQiOiJ3ZWJwIiwicmVzaXplX3RvX2xpbWl0IjpbMTYwMCw5MDBdLCJzYXZlciI6eyJzdHJpcCI6dHJ1ZSwicXVhbGl0eSI6NzV9fSwicHVyIjoidmFyaWF0aW9uIn19--3bc8a2c9d65e3b087c0c0b37dcfb642bb247bc73/WIN_20260626_20_21_17_Pro.jpg)

# Devlog 18/Ship 1

I made a simple, affordable, and reliable take on the Petamentor. The Upcycler is a machine that turns plastic water bottles into 3D printing filament.

The process is as follows: smooth out any bumps and ridges on a 2L PET soda bottle using a heat gun. Use a bottle cutter to cut the bottle into a long 7mm wide strip. Cut down one end to a long point, and feed that point through the nozzle of the heat block.

Plug in the Upcycler's 12V 5A power supply and make any changes to the settings you would like in the menu. However, the default settings are what I would personally recommend from extensive testing. Test to make sure that the thermistor is operational by pressing your finger onto the heat block. There should be a change by a degree or two. Select the "motor status" option to put the Upcycler into Running mode. CAUTION: the Upcycler's heat block will get very hot! DO NOT TOUCH IT!!!!!

Wait until the heat block reaches 180 degrees C. Use a pair of pliers to begin pulling the plastic. You only need to pull until the plastic reaches the spool. Weave the plastic through one of the slots on the side of the spool. You may then leave the Upcycler to work on its own. Processing a full 2L soda bottle may take several hours.

Using the pulled PET in your 3D printer will require custom settings from normal PET. Since each 3D printer and brand of bottle will make the settings vary, I cannot give much advice. However, I can recommend making the nozzle hotter, as that seems to be a general theme for homemade PET.

Wow, that was quite the user's manual!

A challenge that I faced while making the Upcycler was the budget. I knew from the start that I wanted something for less than $100. The closest kits I could find online cost $150. However, as development went on, I managed to get the cost down to a mere $48.43! One big milestone I achieved in budgeting was the motor. The standard Petamentor uses a high-torque 12V 3RPM DC motor, with the cheapest one I could find being $10. However, using smart engineering, I made a diabolical 30:1 gear ratio, allowing me to use much cheaper 28BYJ-48 stepper motors (which only cost $3 each!) Additionally, using the DC motors would have forced me to buy expensive 12V power modules, which generally cost $15 dollars each. Avoiding that constraint, I could use simpler 12V 5A power supplies that cost only $8.

Something that I am proud of in the Upcycler is its dual-mode UI. While you use the Upcycler in its Running mode, you may hear periodical pauses in the motor's humming. Those pauses are caused when the Arduino Uno R3 switches from outputting commands to reading information from the thermistor. It does not have the capability to do both at the same time. Even worse was the joystick. With the constant updates the Arduino needs from the joystick to make navigation smooth, the motor would hardly run at all! To fix this problem, I cleverly separated the code into two parts: a menu mode and a Running mode. In the menu mode, all the Arduino does is read info. It can check the thermistor much faster than in the Running mode, and you can use the Joystick freely. However, when you switch over to Running mode, the joystick is mostly disabled. Instead, the Arduino can focus on outputs, like the motor and the MOSFET powering the heater. However, there are still occasional pauses to check the heat block's temperature (hence the periodical pauses). I also integrated the exit feature into that pause, so if you are holding the joystick down at the moment of the reading, you will exit back into menu mode. I am proud of this workaround I made in the code because I would have had to use a more powerful chip (or two Arduinos!) without it. I managed to fully capitalize on the power of a weak chip to fulfill my criteria.

![Another image of the completed Upcycler V3](https://stardance.hackclub.com/rails/active_storage/representations/proxy/eyJfcmFpbHMiOnsiZGF0YSI6ODc2MDIsInB1ciI6ImJsb2JfaWQifX0=--c31c2ff02727d5c16557d0cf270926f7c3b5670a/eyJfcmFpbHMiOnsiZGF0YSI6eyJmb3JtYXQiOiJ3ZWJwIiwicmVzaXplX3RvX2xpbWl0IjpbMTYwMCw5MDBdLCJzYXZlciI6eyJzdHJpcCI6dHJ1ZSwicXVhbGl0eSI6NzV9fSwicHVyIjoidmFyaWF0aW9uIn19--3bc8a2c9d65e3b087c0c0b37dcfb642bb247bc73/WIN_20260627_12_28_33_Pro.jpg)
