<!--style>
details > summary {
  font-size: 150%;
  padding: 4px;
  width: 600px;
  cursor: pointer;
  color:DeepSkyBlue;
}
h1 {color:DodgerBlue;}
h2 {color:DeepSkyBlue;}
</style-->

[//]: # (Image References)

[image1]: ./assets/markdown.svg "Markdwonn"
[image2]: ./assets/youtube-openmanipulator.png "YouTube - OpenMANIPULATOR-X"
[image3]: ./output_files/color_figures_test2.jpg "Color thresholds"
[image4]: ./output_files/color_th_figures_test1.jpg "S threshold"
[image5]: ./output_files/gradient_th_figures_straight_lines2.jpg "Gradient thresholds"
[image6]: ./output_files/pipeline_figures_straight_lines1.jpg "Binary result"
[image7]: ./examples/color_fit_lines.jpg "Fit Visual"
[image8]: ./examples/example_output.jpg "Output"

# 1. hét - bevezetés


## Hova fogunk eljutni a félévben?
- A félév első fele: mobil robotok, szenzorok, aktuátorok szimulációja. Térképezés, lokalizáció és navigáció:  
  <a href="https://www.youtube.com/watch?v=L2L7snV4sCs"><img height="400" src="./assets/youtube-navigation.png"></a>

- A második fele: robotkarok szimulációja és mozgatása, direkt és inverz kinematika:  
  <a href="https://www.youtube.com/watch?v=mm2vKYH-Jy8"><img height="400" src="./assets/youtube-openmanipulator.png"></a>

 - **A tárgy teljesítése: csoportos házifaladat!**

***

## Mi is az ROS?
A ROS = Robot Operating System, de valójában ez nem egy operációs rendszer, hanem egy olyan middleware, melyet a robotikában széles körben alkalmaznak. Nyíltforráskódú és könyvtárai segítségével lehetővé teszi a robot alkalmazások gyors fejlesztését. Sok előre beépített funkciót tartalmaz, amiket meg fogunk ismerni a félév során, páldául kamerák és más szenzorok kezelése, térképezés és útvonaltervezés, telemanipuláció, stb. Fejlesztését 2007-ben kezdte a Stanford egyetem, 2008-ban csatlakozott a fejlesztéshez a Willow Garage és 2013 óta az OSRF gondozásában, ami 2017-ben Open Robotics-ra változtatta a nevét. 2018 óta a Microsoft és az Amazon részt vesz a ROS fejlesztésében.

Ugyan a Microsoft 2018 óta érdeklődik a ROS iránt, és mostmár telepíthető Windows-ra is, továbbra is a Linux operációs rendszer a legelterjedtebb, ezt fogjuk használni mi is a WSL (Windows Subsystem Linux) segítségével. Bár egyre több programnyelv támogatott a C++ és Python programozási nyelvek a legelterjedtebbek ROS esetén, mi is ezeket fogjuk használni. A ROS-hoz készített alkalmazásokat/komponenseket node-oknak nevezzük, melyek közötti kommunikációt a ROS valósítja meg, mivel a kommunikáció TCP/IP alapú könnyen fejleszthetünk több, hálózatba kötött számítógépen elosztott alkalmazásokat. A robotot vezérlő ROS alkalmazás tehét sok, egymással kommunikáló node-ból épül fel. 

***

## Milyen szoftvereket fogunk használni?

<details>
<summary>Visual Studio Code</summary>

  - Letöltés:  
    - Windows:  
      https://code.visualstudio.com/
    - Linux:  
      Snap store-ból: `sudo snap install --classic code`
  - Javasolt extension-ök:
    - Markdown All in One
    - C/C++
    - Python
    - CMake Tools
    - ROS
    - Remote - SSH
    - Remote - WSL
</details>

<details>
<summary>Markdown</summary>

  ![alt text][image1]  
  A Markdown egy 2004-ben létrehozott, szövegek annotálására szolgáló jelölőnyelv. Könnyen olvasható és írható, fő alkalmazási területei a kolaborációs eszközök, a műszaki és tudományos publikálás. Ezt használja például a GitHub (GFM = GitHub Flavoured Markdown) is dokumentálásra, érdemes megtanulni, mert jelenleg ez a de facto standard a szakmában dokumentálásra. Érdemes odafigyelni, hogy a GFM esetén sok html tag nem használható! Nem lehet például átszínezni a szöveget, vagy tetszőleges méretet változtatni.

  Hasznos linkek a Markdownról:

  * https://en.wikipedia.org/wiki/Markdown
  * https://github.com/adam-p/markdown-here/wiki/Markdown-Cheatsheet
  * https://www.markdownguide.org/extended-syntax/
  * https://gist.github.com/seanh/13a93686bf4c2cb16e658b3cf96807f2

  És egy pár példa:

  * Header-ök:
    ```markdown
    # H1
    ## H2
    ### H3
    #### H4
    ##### H5
    ###### H6
    ```
  * Betűtípusok:  
    ```markdown
    *italic* vagy _italic_
    **bold** vagy __bold__
    ~~strikethrough~~
    ```
  * Listák:
    ```markdown
    Rendezett lista
    1. item
    2. item
    3. item
   
    Rendezetlen
    - item
    * item
    + item
    ```
  * Vizszintes vonal:
    ```markdown
    három vagy több
    ___
    ---
    ***
    ```
  * Programkód:
    ```markdown
    `code`
    ```
    vagy  
    ````markdown
    ```python
    s = "Python syntax highlighting"
    print(s)
    ```
    ````
  * Linkek:
    ```markdown
    [inline-style link](https://www.google.com)

    [inline-style link with title](https://www.google.com "Google's Homepage")
    ```
  * Képek
    ```markdown
    ![alt text](https://upload.wikimedia.org/wikipedia/commons/2/2f/Google_2015_logo.svg "Google Logo Text")
    ```
  * Táblázatok:
    ```markdown
    A kettőspontokkal lehet igazítani az oszlop tartalmát

    | Balra         | Középre       | Jobbra |
    | ------------- |:-------------:| ------:|
    | col 3 is      | right-aligned |  $1600 |
    | col 2 is      | centered      |    $12 |
    | zebra stripes | are neat      |     $1 |
    ```

</details>

<details>
<summary>GIT</summary>

  - ### GIT parancssorból  
    git clone <remote-repo-url>
    git clone -b <branchname> <remote-repo-url>
    git clone --recurse-submodules <remote-repo-url>
    git pull
    git add hello.py
    git add .
    git commit -m "commit message"
    git push

  - ### GitKraken  
    https://www.gitkraken.com/  
    Elérhető Windowsra és Linuxra is  
    Publikus repohoz ingyenesen használható

</details>

<details>
<summary>Windows 10 WSL 2</summary>

WSL telepítése:  
https://docs.microsoft.com/en-us/windows/wsl/install-win10

Mi a WSL? Mi a WSL2?

</details>

<details>
<summary>XServer (VcXsrv)</summary>

Letöltés:
https://sourceforge.net/projects/vcxsrv/

Képek a konfigról

Bash script a display inithez


</details>

<details>
<summary>Terminator</summary>

  `sudo apt install terminator`

  `Ctrl+Shift+e`

  `Ctrl+Shift+o`

  `Ctrl+Shift+w`

  `Ctrl+Shift+q`

</details>

<details>
<summary>ROS Melodic</summary>

  - ### A ROS telepítése
  - ### Catkin workspace parancsok

  - ### ROS parancsok

</details>


***
## ROS alapok

- ## ROS Master

- ## Publisher

- ## rqt

- ## Subscriber

rosnode list, rostopic list, rostopic info

***
## Turtlesim

### Twist üzenetek

### Keyboard teleop

### Hello World! Első saját ROS node-unk


http://wiki.ros.org/ROS/Introduction

http://wiki.ros.org/ROS/Tutorials