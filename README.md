# SmartKnob firmware for rp2040 board
SmartKnob is an open-source input device with software-configurable endstops and virtual detents.

A brushless gimbal motor is paired with a magnetic encoder to provide closed-loop torque feedback control, making it
possible to dynamically create and adjust the feel of detents and endstops.

# Hardware
The used hardware is documented on the seperate [repository](https://github.com/lersle/SmartKnob-rp2040-hardware).

# SmartKnob firmware guide
The following prerequsites are mandatory.

## Requirements
- [Smartknob-rp2040](https://github.com/lersle/SmartKnob-rp2040-hardware>)

## Getting started
Complete guide with every extension, plugin etc. I used.
In your project folder create a folder named SmartKnob-rp2040.

### Visual Studio Code
Install the latest [Visual Studio Code](https://portapps.io/app/vscode-portable/#installation) portapps version to get a blank vscode setup. Follow the installation guide. After the installation open vs-code.

### Ubuntu WSL
Open command line and type "wsl.exe --install --no-distribution" to start the installation of the Windows Subsystem for Linux.

    wsl.exe --install --no-distribution

To use the Ubuntu Subsystem you will need to reboot your device.
Then type Ubuntu in the windows search bar to start the VM. Set your new username and password.

In VS-Code open the extensions tab and install the WSL extension.
Extension ID:

    ms-vscode-remote.remote-wsl

From the bottom left corner select "Connect to WSL".
Under File, select Open Folder, then type /mnt/"drive"/"Path of project folder". 

### C/C++ Extension Pack
Install this extension pack to add support for CMake builds.

    ms-vscode.cpptools-extension-pack

### Git Graph (optional)
This extension isn't mandatory but helps with keeping your git repos organised.
Search for mhutchie.git-graph in the extension tab.

    mhutchie.git-graph

### GItHub repos
Open a new terminal and clone these repos:

    git clone --recurse-submodules https://github.com/lersle/SmartKnob-rp2040-firmware.git
    git clone --recurse-submodules https://github.com/lersle/pico-sdk.git
    
