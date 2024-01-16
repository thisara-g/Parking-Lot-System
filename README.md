# Parking-Lot-System
EN1190 - Engineering Design Project 

## Contents

- [1. Overview](#1-overview)
- [2. Our Approach](#2-our-approach)
- [3. Project Setup](#3-project-setup)
  - [3.1 GNU Radio](#31-gnu-radio)
  - [3.2 GUI Setup](#32-gui-setup)
- [4. Contributors](#4-contributors-team-radioheads)

___

## 1. Overview

A point-to-point digital wireless communication system implemented with [GNU Radio](https://www.gnuradio.org/) to transmit and receive

- Image
- Bit Stream
- Real-time audio

 using devices such as Blade-RF.

___

## 2. Our Approach

1. Image Transmission
    - [x] Simulation
    - [x] Physically

- _Modulation Scheme_ : **2-FSK**
- _Evaluation Metric_ : Mean Squared Error (_MSE_) between the transmitted Image(_T_) and Received Image(_R_)
- MSE for Monochrome image of size _MxN_ is defined as

    _MSE_ $= \frac{1}{M \cdot N} \sum_{i=1}^{M} \sum_{j=1}^{N} [T(i,j) - R(i,j)]^{2}$

2. Binary Data Stream Transmission
    - [x] Simulation
    - [x] Physically

- _Modulation Scheme_ : **2-GFSK**
- _Evaluation Metric_ : Bit Error Rate (_BER_)

3. Voice Transmission (Real Time voice captured from MIC / Recorded voice clip)
    - [x] Simulation
    - [x] Physically

- _Modulation Scheme_ : **2-GFSK**
- _Evaluation Metric_ : Based on the Quality of the Received Voice (Evaluated by Hearing it)

___

## 3. Project Setup

```
NOTE : You have the option to directly refer to the GRC files that contain the relevant flowgraphs. It is not mandatory to set up the Interface.
```

### 3.1 GNU Radio

[GNU Radio](https://www.gnuradio.org/) is an open-source toolkit for software-defined radio development. It provides signal processing blocks to build versatile radio systems, including sophisticated in wireless communication systems.

Refer to their documentation on [how to set up GNU Radio](https://wiki.gnuradio.org/index.php/InstallingGR) on your device along with bladeRF driver installation.

Prefered : **Linux Environment**
```
We attempted driver installation in a Windows environment, but configuring the drivers proved challenging. It's recommended to opt for a Linux OS for a smoother GNU Radio installation.
```

### 3.2 GUI Setup

We used [Streamlit](https://streamlit.io/) to interface our project with GRC flow graphs and python files generated by them.

1. Clone the repository:

    ```bash
    git clone https://github.com/SasikaA073/CDP-communication-system
    cd CDP-communication-system
    cd ST_Webapp
    ```

2. Install venv

    ```bash
    sudo apt-get update
    sudo apt-get install python3-venv
    ```

3. Create a Python virtual environment named "gnu":

    ```bash
    python3 -m venv gnu
    ```

4. Activate the virtual environment:

    ```bash
    source gnu/bin/activate
    ```

5. Install the required Python packages from the `requirements.txt` file:

    ```bash
    pip3 install -r requirements.txt
    ```

6. Run the following to start the interface

    ```bash
    streamlit run Home.py
    ```

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
