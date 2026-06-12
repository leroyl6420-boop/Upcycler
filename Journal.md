# Devlogs

Hi! Welcome to my project journal! Before you take a peek, you may realize that the commits do not match the logs. That is because this is literally my first time using Github and I didn't really know how to do a journal for devlogs until I was gonna ship :P
If you're a reviewer reviewing my project and you really need proof of the devlogs, I wrote quick summaries under each of my timelapses in Lapse, which is also what my devlogs will be based on. If you need anything from me to clear things up, please let me know in any way. I check Slack very often. Sorry for the inconvenience! Thank you for all your hard work :)

# Devlog 1
1h 0min 27sec Logged

I started working on my Upcycler project today! I need to make a full 3D model as a plan, so I found some files online of a motorized mechanism that pulls the PET in a PET puller. I imported them into my project, but I discovered that they need 608 2RS bearings, M8-1.25 60mm screws, and M8-1.25 hex nuts to be fully put together. I found the dimensions of those parts online and modeled them myself! Afterwards, I brought all the part studios into an assembly and put together the first model of the body (you can find models in branch First-CADS). However, I still need to greatly adapt the puller mechanism to use 28BYJ-48 stepper motors instead of expensive 12V 3RPM DC motors. I started that today by calculating the grams of force per centimeter sqaured of each motor. My motor was approximately 20x weaker than theirs. To compensate for friction, bending of the materials, and the fact that the spool's axle has only one attachment point, I estimated the need for a 30:1 ratio. I modeled the driven gear as large as I could, but my math still does not see my mechansim working. I'll need to improvise a geartrain for everything to work. 

![Picture of Big Gear](Images/BGDevlog1.png)
![Picture of Upcycler](Images/Devlog1.png) 

# Devlog 2
1h 1min 12sec Logged

I worked on the geartrain for my Upcycler! I finished modeling the big gear to fit the spool and the axle, and I'm getting started on the other gears. I've decided to incorporate four gears: the driver gear will be connected to the 28BYJ-48 stepper motor, the driven gear will be above that (at a 24:7 ratio), and the driven gear will be on the same axle the small gear, which will drive the big gear (at a 61:7 ratio). That should result it a roughly 30:1 ratio. Of course, to fit the new axles and gears, I had to change the body of the puller a lot. I removed the mounting holes meant for the original motor, and I made new slots for new bearings. 

![Another Picture of Big Gear](Images/BGDevlog2.png) 
![Second Picture of Upcycler](Images/Devlog2.png) 

#
