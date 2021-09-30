# Smart Stove
Winner of Best Hardware Hack in NewHack 2020

# Inspiration
This idea is inspired by experiences of forgetfulness we all face when cooking. Sometimes I leave the room for too long and the pot starts overheating. Sometimes, I need to know the temperature of the stove to make a good recipe. And whenever I am done, I always wonder to myself “Did I turn off the stove?” The Smart Stove intends to solve all these problems, improving the cooking experience and providing users with peace of mind.

# What it does
The Arduino component is equipped with a temperature/humidity and gas sensor. Additionally, it has 6 LEDs of varying colours, a buzzer, and a switch button. Every 3 seconds, the sensors record values. The colour of the LEDs represent the heat of the stove, with blue representing safe and red representing hot. The switch toggles Alert Mode, which can be pressed by the user before they leave the room. If the temperature becomes very hot while on alert mode, the buzzer will make noise until the button is pressed again, indicating that the user has returned to the room and recognized the danger. The data recorded from the sensors is sent through Node Red and creates a display of the current values which can be accessed from any wireless device. This is connected to an app, which the user can use to see the heat and gas levels of the stove from anywhere. If these values reach dangerous levels, the user has the option to call the fire department or a contact they set who can turn the stove off.

# How we built it
The Arduino was built using a lot of trial and error, as this is the first time any of the group members have used this tool. Adobe XD was used to make the app interface. Node-RED was used to create the interactive display.

# Challenges we ran into
Initially, we struggled with testing our temperature/humidity sensor and how to upload a library. Deeper into the project, we ran into the issue of making an aesthetically pleasing and easy to use app interface along with the struggle to find a way to develop an app or demo with our experience level. Through the course of the hackathon we were able to overcome our challenges and create a project we’re proud of.

# Accomplishments that we're proud of
We’re proud of learning to use arduino and create a hardware component that meets its desired criteria. Additionally, we are very proud of coordinating the results from the arduino with Node Red to create a visual display of real-time sensor values. Overall, we are proud of coming up with a workable idea that can provide benefits to many people’s lives.

# What we learned
In this hackathon, we learned various things from the workshops and mentors. At the start of the hackathon, none of us were familiar with using hardware. Throughout the hackathon, we learned how to use Arduino to utilize sensors and LED lights, and our mentors gave us feedback on what was considered “good” UI design. To push the project further, our mentor recommended us to use Node-RED, and we were taught by our mentor how to use it.

# What's next for Smart Stove
The next steps for Smart Stove is to implement more coordination with the stove and possibly add a way to detect and show a thermal image of the food on the stove to make the smart stove an extra aid to cooking for beginners.

# Devpost URL
https://devpost.com/software/smart-stove

# Video of Smart Stove in Action
https://www.youtube.com/watch?v=yy8wtMYdA0A&ab_channel=CindyJin