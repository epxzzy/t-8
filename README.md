# t-8
handheld experiment and MVP-EDA-OOAD nightmare.





## requirements / prerequisites 
- #### Hardware (optional)
    - an esp32 microcontroller
    - USB cable ("data" cable)
- #### Software
    - ESP-IDF v5.x
    - Python 3.9+ (ESP-IDF needs it, for venv)
    - CMake
- #### Software for simulation (optional)
    - vscode (any forks would also do)
    - wokwi access key && wokwi extension for vscode(or forks)


## setup:

#### linux: 

1. get ESP-IDF:

    - arch linux:  
        using yay  
        `> yay -S esp-idf`  

        if it installed successfully it should tell you to do  
        `> source /opt/esp-idf/export.sh`  
        
        either that or something similar which btw should be ran in every new shell that is meant to be used for esp-idf related activities. ideally it should be installed in:  
        `/usr/share/esp-idf`
        
        if not then just follow the logs they should be able to just guide you.  
        once all done you can do  
        `> idf.py --version`  

        to verify the install.

    - others:  
        follow the official guide:
        https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/linux-setup.html


2. other software requirements:  
    i think you got this.

3. clone this repo:  
    `> git clone https://github.com/epxzzy/t-8.git`  

    `> cd t-8`  


#### windows:

1. Install ESP-IDF Tools Installer:  
https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/windows-setup.html

2. Use ESP-IDF PowerShell (important — don’t skip this)  
    Verify installation:  
        `> idf.py --version`

3. other software requirements:  
    i think you got this one probably.

4. clone this repo:  
    `> git clone https://github.com/epxzzy/t-8.git`  

    `> cd t-8`  

#### macOS: (yall are pretty much on your own)
 
https://docs.espressif.com/projects/esp-idf/en/latest/esp32/get-started/macos-setup.html  
hope this helps :)


## building

this part should be similar for most machines.  
instructions below assume you are in the root directory.   

if you are on linux run this before you proceed with anything:  
`> source /opt/esp-idf/export.sh`  

set target:  
`> idf.py set-target esp32`  
add dependency:
`> cd firmware && idf.py add-dependency "espressif/esp_websocket_client^1.6.1"`
and then to build:  
`> cd ../ && idf.py build`

if you have the hardware, plug it in and then:  
`> idf.py flash monitor`

if you do not have the hardware(holy brokie),  
i am setting up wokwi so you can simulate the  
thing. i will expand more on this later.

## simulating (via wokwi) 

first install via the official installation guide:  
https://docs.wokwi.com/vscode/getting-started#installation

once you have the extension activated you can just hit `ctrl + shift + p`  
and input `Wokwi: Start Simulation` to run it. its that simple.

make a few changes, tweak a few things, build via espidf and the simulation  
will automatically reflect the changes.

if you would like to tweak wokwi related stuff:   
`./diagram.json` - responsible for the circuitry    
`./wokwi.toml` - wokwi configuration   

