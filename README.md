# Parking-Lot-System
EN1190 - Engineering Design Project 

## Contents

- [1. Overview](#1-overview)
- [2. Our Approach](#2-our-approach)
- [3. Project Setup](#3-project-setup)
  - [3.1 PCB](#31-pcb)
  - [3.2 Enclosure](#32-enclosure)
- [4. Contributors](#4-contributors-team-phoenix)

___

## 1. Overview

The idea behind this project was to identify a problem faced by a majority of citizens and provide a feasible solution which would help solve this problem, by also taking feedback from the citizens to as whether this idea would be something they would want to invest in.

___

## 2. Our Approach

1. Breadboard implentation

- We started with getting Arduino modules then writing the code according to the functionality we needed.


2. Power Supply 

- Battery : We used 2 Li-ion 18650 batteries in series.
- Charging : For charging we implemented a circuit with auto cut-off at 8.4V since we used 2 batteries in series.

3. Enclosure

- We drew an initial sketch of what our product should look like and also made 3D model of it.
![Product Model Intial](https://github.com/thisara-g/Parking-Lot-System/assets/135704538/5b1d5433-3192-4bef-8644-98e0ba9b5aac)


___

## 3. Project Setup



### 3.1 PCB

- For the PCB we used abstraction to combine different modules together, for example combining the charging and regulation circuit with ATmega 328P when designing the schematic for the PCB.

![Product Model Intial](https://github.com/thisara-g/Parking-Lot-System/assets/135704538/0b2dd00a-f8e8-4dd5-ae87-392b9664e2eb)


### 3.2 Enclosure

- Initial enclosure design was as shown above but we identified that the user would not be able to identify the correct direction if the product is not held in the correct direction as a result the enclosure was changed to support that.


___

## 4. Contributors (Team Phoenix)

- [Thisara Gunawardana](https://lk.linkedin.com/in/thisara-gunawardana-3a1774264)
- [Nadil Gunawardana](https://lk.linkedin.com/in/)
- [Raveen Pathirana](https://lk.linkedin.com/in/)
- [Kehan Manamperi](https://lk.linkedin.com/in/)

___
<div style="display: flex; align-items: center;">
    <img src="https://upload.wikimedia.org/wikipedia/en/6/60/University_of_Moratuwa_logo.png" width="100px" height="94px" style="margin-left: 10px;" />
   
<img src="https://ent.uom.lk/wp-content/uploads/2021/07/logo-entc-copy.png" alt="Alt text" width="200px" height="60px" style="clip: rect(50px, 100px, 50px, 30px);" />
    
</div>
