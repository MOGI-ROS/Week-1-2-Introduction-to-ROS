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
[image2]: ./assets/terminator.png "Terminator"
[image3]: ./assets/vcxsrv_1.png "VcXsrv"
[image4]: ./assets/vcxsrv_2.png "VcXsrv"
[image5]: ./assets/vcxsrv_3.png "VcXsrv"
[image6]: ./assets/rqt_1.png "rqt"
[image7]: ./assets/rqt_2.png "rqt"
[image8]: ./assets/rqt_3.png "rqt"
[image9]: ./assets/rqt_4.png "rqt"  


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
  A Markdown egy 2004-ben létrehozott, szövegek annotálására szolgáló jelölőnyelv. Könnyen olvasható és írható, fő alkalmazási területei a kollaborációs eszközök, a műszaki és tudományos publikálás. Ezt használja például a GitHub (GFM = GitHub Flavoured Markdown) is dokumentálásra, érdemes megtanulni, mert jelenleg ez a de facto standard a szakmában dokumentálásra. **Azért is érdemes megtanulni, mert ennek segítségével kell dokumentálni a házifeladatot is.** Érdemes odafigyelni, hogy a GFM esetén sok html tag nem használható! Nem lehet például átszínezni a szöveget, vagy tetszőleges méretet változtatni.

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
    A tárgy során GIT verziókevtő rendszert fogunk használni, és a házifeladatot is ebben kell megcsinálni. Regisztráció a [GitHub](https://www.github.com)-on a privát email címetekkel.  
    A legfontosabb GIT parancsok:  

    GIT repo letöltése a default branch-csel:  
    `git clone <remote-repo-url>`  
    GIT repo letöltése a kiválasztott branch-csel:  
    `git clone -b <branchname> <remote-repo-url>`  
    GIT repo letöltése submodule-okkal:  
    `git clone --recurse-submodules <remote-repo-url>`  
    Lokális GIT repoban lévő fájlok állapota, kiválasztott branch  
    `git status`  
    Lokális GIT repo frissítése a szerveren történt változtatásokkal  
    `git pull`  
    Lokális fájlok hozzáadása commit-ra:  
    `git add hello.py`  
    Minden fájl hozzáadása:  
    `git add .`  
    GIT commit:  
    `git commit -m "commit message"`  
    Változások feltöltése a szerverre:  
    `git push`  
    Lokális változások törlése és a legutolsó commitra visszaállítása:  
    `git reset --hard`  
    Új branch létrehozása lokálisan:  
    `git checkout -b <branchname>`  
    Új branch feltöltése a GIT szerverre:  
    `git push --set-upstream origin <branchname>`  
    Branchek közti váltás:  
    `git switch main`  


  - ### GitKraken  
    Ha valaki nem szereti a parancssoros GIT-et, akkor javaslom a [GitKrakent](https://www.gitkraken.com/)-t.  
    Elérhető Windowsra és Linuxra is és publikus repohoz ingyenesen használható!  

</details>

<details>
<summary>Windows 10 WSL 2</summary>

A WSL (2) a Windows Subsystem for Linux (2), ez egy teljesértékű Linux kernel, amivel Linux disztribúciót, pl Ubuntu 18.04, futtathatunk a Windowson belül. A tárgy során olyan Linuxos alkalmazásokat fogunk használni, amiknek szüksége van a GPU 3D gyorsítására, ezért a WSL1 nem felel meg a célnak, de a WSL2 már igen!

A WSL telepítése:  
https://docs.microsoft.com/en-us/windows/wsl/install-win10

Az Ubuntu 18.04 és a 20.04 is elérhető a Microsoft Store-ból. A tárgy során a 18.04 használata javasolt.

</details>

<details>
<summary>XServer (VcXsrv)</summary>

Ahhoz, hogy grafikus Linux alkalmazásokat futassunk szükségünk van egy X szerverre Windowson. Ilyen a [VcXsrv](https://sourceforge.net/projects/vcxsrv/).  

A VcXsrv konfigja:  
![alt text][image3]  
![alt text][image4]  
![alt text][image5]  

Ahhoz, hogy a WSL-ben futó Linux tudjon csatlakozni az X szerverhez, adjuk hozzá a következő pár sort a ~/.bashrc fájlhoz. A .bashrc megnyitása nano szövegszerkesztővel:  
`cd ~`  
`nano .bashrc`  

```bash
export DISPLAY=$(awk '/nameserver / {print $2; exit}' /etc/resolv.conf 2>/dev/null):0
export LIBGL_ALWAYS_INDIRECT=
export LIBGL_ALWAYS_SOFTWARE=1
```

</details>

<details>
<summary>Terminator</summary>

A Terminator egy nagyon hasznos Linuxos terminál, ezt javaslom a tárgy hazsnálata során, mert rengeteg parancssorral fogunk dolgozni.

![alt text][image2]

A Terminator telepítése Linuxon:

  `sudo apt install terminator`

Hasznos Terminator parancsok:  
Parancssor függőleges felosztása:  
  `Ctrl+Shift+e`  
Parancssor vízszintes felosztása:  
  `Ctrl+Shift+o`  
Parancssor bezárása:  
  `Ctrl+Shift+w`  
Terminator (és az összes parancssor) bezárása:  
  `Ctrl+Shift+q`  

</details>

<details>
<summary>ROS Melodic</summary>

  - ### A ROS telepítése  

http://wiki.ros.org/melodic/Installation

Ubuntu 18.04 esetén ROS Melodic  
Ubuntu 20.04 esetén ROS Noetic  

A ROS Melodic 2023-ig, a Noetic 2025-ig támogatott.  
  
  - ### Catkin workspace parancsok

Hozzunk létre egy catkin workspace-t:  

`cd ~`  
`mkdir -p catkin_ws/src`  
`cd catkin_ws`  
`catkin_make`  


`catkin_make`  
`catkin_create_pkg PACKAGE DEPENDENCY1 DEPENDENCY2 ...`  

  - ### ROS parancsok

`roscore`  
`roscd PACKAGE`    
`rosrun PACKAGE NODE`  
`roslaunch PACKAGE LAUNCHFILE`  
`rosnode list`  
`rosnode info /NODE`  
`rostopic list`  
`rostopic info /TOPIC`  
`rostopic echo /TOPIC`  
`rostopic pub /TOPIC MSG "DATA"`  

</details>


***
## ROS alapok

- ## ROS Master

A ROS Master felel az egyes node-ok regisztrációjáért, összeköti a publishereket és a subscriberek, ez írja le a teljes rendszerünk gráfját. Emellett ez tárolja a paramétereket is. Miután a ROS Master összekötötte az egyes node-okat, a node-ok peer-to-peer kommunikálnak, nem a ROS Masteren keresztül. További részletek a [wikin](http://wiki.ros.org/Master).  
A ROS Mastert a `roscore` paranccsal indítjuk el.

```console
david@DavidsLenovoX1:~/catkin_ws$ roscore
Command 'roscore' not found, but can be installed with:

sudo apt install python3-roslaunch
```

Ha a telepítés során nem tettük be a ROS környezetet a .bashrc fájlba, akkor minden terminál ablakban kézzel kell betölteni a környezetet:

`source /opt/ros/melodic/setup.bash`

Ezután már indíthatjuk a ROS Mastert a `roscore`-ral.

```console
david@DavidsLenovoX1:~/catkin_ws$ roscore
... logging to /home/david/.ros/log/52a3b24e-44ff-11eb-8608-00155df615f6/roslaunch-DavidsLenovoX1-327.log
Checking log directory for disk usage. This may take a while.
Press Ctrl-C to interrupt
Done checking log file disk usage. Usage is <1GB.

started roslaunch server http://172.21.233.33:42697/
ros_comm version 1.14.9


SUMMARY
========

PARAMETERS
 * /rosdistro: melodic
 * /rosversion: 1.14.9

NODES

auto-starting new master
process[master]: started with pid [337]
ROS_MASTER_URI=http://172.21.233.33:11311/

setting /run_id to 52a3b24e-44ff-11eb-8608-00155df615f6
process[rosout-1]: started with pid [348]
started core service [/rosout]
```

___

## ROS Node

Lépjünk be a már létrehozott catkin workspace-ünkbe:

`cd ~/catkin_ws/src`

Új node-ot a `catkin_create_pkg` paranccsal tudunk létrehozni. Megadhatjuk a node-unk függőségeit a létrehozáskor:  
`catkin_create_pkg bme_ros_tutorials roscpp rospy std_msgs actionlib actionlib_msgs`  

Miután létrehoztuk a node-ot, egy üres `src` és `inc` mappa, illetve egy `CMakeList.txt` és egy `package.xml` fájl jn létre.

Ezek a függőségek automatikusan bekerülnek a `CMakeList.txt` és `package.xml` fájlokba, de ezeket később is felvehetjük kézzel.

A CMakeList.txt fájl:

```cmake
cmake_minimum_required(VERSION 3.0.2)
project(bme_ros_tutorials)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  actionlib
  actionlib_msgs
  roscpp
  rospy
  std_msgs
)

...
```

Nyugodtan kapcsoljátok be a C++11 fordítási opciót.

```cmake
## Compile as C++11, supported in ROS Kinetic and newer
add_compile_options(-std=c++11)
```

A package.xml fájl elején adjuk meg a node készítőjének adatait és a licensz típusát. Ha saját magatoknak készítetek ROS node-okat, akkor ezekkel nem kell foglalkoznotok, de ha meg szeretnétek osztani a csomagotokat másokkal, akkor praktikus ezt kitölteni.

A licenszekről bővebben:

http://wiki.ros.org/DevelopersGuide  
https://www.ros.org/reps/rep-0140.html#license-multiple-but-at-least-one

```xml
<?xml version="1.0"?>
<package format="2">
  <name>bme_ros_tutorials</name>
  <version>0.0.1</version>
  <description>The bme_ros_tutorials package</description>

  <!-- One maintainer tag required, multiple allowed, one person per tag -->
  <!-- Example:  -->
  <!-- <maintainer email="jane.doe@example.com">Jane Doe</maintainer> -->
  <maintainer email="dudas.david@mogi.bme.hu">David Dudas</maintainer>


  <!-- One license tag required, multiple allowed, one license per tag -->
  <!-- Commonly used license strings: -->
  <!--   BSD, MIT, Boost Software License, GPLv2, GPLv3, LGPLv2.1, LGPLv3 -->
  <license>BSD</license>
```

A package.xml szintén tartalmazza a létrehozáskor megadott függőségeket.  

```xml
  <buildtool_depend>catkin</buildtool_depend>
  <build_depend>actionlib</build_depend>
  <build_depend>actionlib_msgs</build_depend>
  <build_depend>roscpp</build_depend>
  <build_depend>rospy</build_depend>
  <build_depend>std_msgs</build_depend>
  <build_export_depend>actionlib</build_export_depend>
  <build_export_depend>actionlib_msgs</build_export_depend>
  <build_export_depend>roscpp</build_export_depend>
  <build_export_depend>rospy</build_export_depend>
  <build_export_depend>std_msgs</build_export_depend>
  <exec_depend>actionlib</exec_depend>
  <exec_depend>actionlib_msgs</exec_depend>
  <exec_depend>roscpp</exec_depend>
  <exec_depend>rospy</exec_depend>
  <exec_depend>std_msgs</exec_depend>
```

Ezt azért praktikus megadni, és ha kell bővíteni a szükséges függőségekkel, hogy a ROS már fordítás előtt tudja, hogy milyen csomagokra van szükség. Ilyenkor a szükséges csomagok telepíthetők a következő paranccsal:

`rosdep install -y --from-paths src --ignore-src --rosdistro melodic -r`

Enélkül csak fordítás közben derül ki, ha valami hiányzik.

Fordítsuk le a catkin workspace-ünket az új (egyelőre még üres) csomagunkkal. Ezt a catkin workspace gyökerében tudjuk megtenni:

`cd ~/catkin_ws`

`catkin_make`

Fordítás után be kell töltsük az új környezetet, ami már tartalmazza az új csomagunkat:

`source devel/setup.bash`

A roscd paranccsal könnyen meggyőződhetünk róla, hogy a csomagunkat látja a ROS:

`roscd bme_ros_tutorials`

Hozzuk létre a basic_node.cpp fájlt a src mappában:

`cd src`

`touch basic_node.cpp`

A basic_node.cpp fájl tartalma:

```cpp
#include <ros/ros.h>

int main(int argc, char** argv)
{
	int count = 0;
	ros::init(argc, argv, "basic_node"); // Init the node with name "basic_node"
	ros::NodeHandle nh;                  // NodeHandle will fully initialze the node
	ros::Rate loop_rate(1);              // 1Hz
	
	while (ros::ok())                    // run the node until Ctrl-C is pressed
	{
        // print info to std out
		ROS_INFO("basic_node cpp is running. count = %d", count);
			
		count++;
		
		loop_rate.sleep();                // The loop runs at 1Hz
	}
}
```
Egészítsük ki a CMakeLists.txt fájlt, hogy tartalmazza az új futtatható kódunkat:

```cmake
###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)

add_executable(basic_node src/basic_node.cpp)
target_link_libraries(basic_node ${catkin_LIBRARIES})

```

És utána fordítsuk újra a catkin orkspace-t (a workspace gyökréből):

`cd ~/catkin_ws`  
`catkin_make`

Indítsuk el az első node-unkat a `rosrun bme_ros_tutorials basic_node` paranccsal:

```console
david@DavidsLenovoX1:~/catkin_ws$ rosrun bme_ros_tutorials basic_node 
[ERROR] [1608721117.404835100]: [registerPublisher] Failed to contact master at [172.21.233.33:11311].  Retrying...
```

Aktív ROS Master nélkül azonban nem lehet elindítani a node-okat. Indítsunk egy ROS Mastert egy másik terminál ablakban:  
`roscore`  
Ezek után el is indul a node-unk:

```console
david@DavidsLenovoX1:~/catkin_ws$ rosrun bme_ros_tutorials basic_node 
[ERROR] [1608721181.600462500]: [registerPublisher] Failed to contact master at [172.21.233.33:11311].  Retrying...
[ INFO] [1608721184.271224200]: Connected to master at [172.21.233.33:11311]
[ INFO] [1608721184.275441900]: basic_node cpp is running. count = 0
[ INFO] [1608721185.275595900]: basic_node cpp is running. count = 1
[ INFO] [1608721186.275650300]: basic_node cpp is running. count = 2
[ INFO] [1608721187.275671600]: basic_node cpp is running. count = 3
...
```
Csináljuk meg ugyanezt a példát Pythonban is a node scripts mappájában:  
`roscd bme_ros_tutorials`  
`mkdir scripts`  
`cd scripts`  
`touch basic_node.py`

A basic_node.py tartalma:

```python
#!/usr/bin/env python

import rospy

count=0
rospy.init_node('basic_node')  # Init the node with name "basic_node"
rate = rospy.Rate(1)           # 1Hz

while not rospy.is_shutdown(): # run the node until Ctrl-C is pressed

    # print info to std out
	rospy.loginfo("simple_node in python is running. count= %d",count)
	
	count+=1
	
	rate.sleep() # The loop runs at 1Hz
```

Indítsuk el a node-ot a `rosrun bme_ros_tutorials basic_node.py` paranccsal:

```console
david@DavidsLenovoX1:~/catkin_ws/src/bme_ros_tutorials$ rosrun bme_ros_tutorials basic_node.py
[rosrun] Couldn't find executable named basic_node.py below /home/david/bme_catkin_ws/src/bme_ros_tutorials
[rosrun] Found the following, but they're either not files,
[rosrun] or not executable:
[rosrun]   /home/david/bme_catkin_ws/src/bme_ros_tutorials/scripts/basic_node.py
```

A létrehozott fájl nem futtatható, ezért először be kell állítsuk a fájl futtathatóságát:  
`chmod +x basic_node.py`

Ezután próbáljuk meg újra elindítani.  
Ha a következő hibát látjátok az azért van, mert a fájl a Windowsnak megfelelő sorfvégződéssel lett létrehozva (CRLF), ezt le kell cseréljük Unix típusú sorvégekre (LF). Ez a Visual Studio Code-ban egyszerűen megtehető a jobb alsó sarokban.

```console
david@DavidsLenovoX1:~/catkin_ws/src/bme_ros_tutorials/scripts$ rosrun bme_ros_tutorials basic_node.py
/usr/bin/env: ‘python\r’: No such file or directory
```

Vegyük észre, hogy Python kódok esetén nem kell catkin_make-et futtatnunk, legalábbis, ha ennyire egyszerű a Python kódunk. Ha vannak importált saját library-k, akkor kicsit bonyolultabb a helyzet, de ezt majd később megnézzük.

___


## Publisher

A ROS publisher adatokat küld a többi node-nak. Csak azok az node-ok kapják meg a publisher által küldött adatokat, akik feliratkoznak rá, ezek a node-ok a subscriber-ek. Hozzuk létre az első publisherünket C++-ban:

`roscd bme_ros_tutorials`

Hozzuk létre a publisher.cpp fájlt a src mappában:

`cd src`

`touch publisher.cpp`

A publisher.cpp fájl tartalma:  
```cpp
#include "ros/ros.h"
#include "std_msgs/Int32.h"           // Message type used in the node

int main(int argc, char **argv)
{
	ros::init(argc, argv, "publisher"); // Init the node with name "publisher"
	ros::NodeHandle nh;                 // NodeHandle will fully initialze the node

    /**
    * The advertise() function is how you tell ROS that you want to
    * publish on a given topic name. This invokes a call to the ROS
    * master node, which keeps a registry of who is publishing and who
    * is subscribing. After this advertise() call is made, the master
    * node will notify anyone who is trying to subscribe to this topic name,
    * and they will in turn negotiate a peer-to-peer connection with this
    * node.  advertise() returns a Publisher object which allows you to
    * publish messages on that topic through a call to publish().  Once
    * all copies of the returned Publisher object are destroyed, the topic
    * will be automatically unadvertised.
    *
    * The second parameter to advertise() is the size of the message queue
    * used for publishing messages.  If messages are published more quickly
    * than we can send them, the number here specifies how many messages to
    * buffer up before throwing some away.
    */

	ros::Publisher pub = nh.advertise<std_msgs::Int32>("publisher_topic", 10);
	
	ROS_INFO("Publisher C++ node has started and publishing data on publisher_topic");
	
	ros::Rate loop_rate(1); // 1 Hz
	
	std_msgs::Int32 count;  // Count is now a ROS Int32 type variable that is ready to be published
	count.data=0;           // Initializing count
	
    while (ros::ok())       // Run the node until Ctrl-C is pressed
    {		
		pub.publish(count); // Publishing data on topic "publisher_topic"
		count.data++;	
		loop_rate.sleep();  // The loop runs at 1Hz
	}
}
```

Adjuk hozzá az új node-unkat a CMakeLists.txt fájlhoz:

```cmake
add_executable(publisher src/publisher.cpp)
target_link_libraries(publisher ${catkin_LIBRARIES})
```

Fordítsuk újra a catkin workspace-t, töltsük be a környezetet és indítsuk el a node-ot!

`rosrun bme_ros_tutorials publisher`

```console
david@DavidsLenovoX1:~/catkin_ws$ rosrun bme_ros_tutorials publisher
[ INFO] [1608741335.639818400]: Publisher C++ node has started and publishing data on publisher_topic
```

Nézzük meg a `rosnode list` parancsot, látjuk a listában a publisher node-ot:

```console
david@DavidsLenovoX1:~$ rosnode list
/publisher
/rosout
```

A `rosnode info /publisher` paranccsal nézzük meg a node-unk részleteit:

```console
david@DavidsLenovoX1:~$ rosnode info /publisher
--------------------------------------------------------------------------------
Node [/publisher]
Publications: 
 * /publisher_topic [std_msgs/Int32]
 * /rosout [rosgraph_msgs/Log]

Subscriptions: None
```

Látjuk, hogy a publisher_topic-ba küld adatokat és semmire sincs feliratkozva.

Nézzük meg a topicokat is a `rostopic list` paranccsal:

```console
david@DavidsLenovoX1:~$ rostopic list
/publisher_topic
/rosout
/rosout_agg
```

Nézzük meg a publisher_topic részleteit a `rostopic info /publisher_topic` paranccsal:  

```console
david@DavidsLenovoX1:~$ rostopic info /publisher_topic
Type: std_msgs/Int32

Publishers: 
 * /publisher (http://172.21.233.33:45573/)

Subscribers: None
```

Látjuk, hogy mi az adat típusa, ki állítja elő és azt is, hogy jelenleg senki sincs feliratkozva erre az adatra.

Iratkozzunk fel az adatra parancssorból a `rostopic echo /publisher_topic` paranccsal:

```console
david@DavidsLenovoX1:~$ rostopic echo /publisher_topic
data: 564
---
data: 565
---
data: 566
---
...
```

És nézzük meg egy újabb terminálban a `rostopic info /publisher_topic`-ot:

```console
david@DavidsLenovoX1:~$ rostopic info /publisher_topic
Type: std_msgs/Int32

Publishers: 
 * /publisher (http://172.21.233.33:45573/)

Subscribers: 
 * /rostopic_4434_1608741899293 (http://172.21.233.33:46787/)
```

Láthatjuk, hogy az adatnak van egy subscriber-e, hiszen a parancssorban echozzuk az adatot.

Csináljuk meg a publisher node-unk Python változatát is `publisher.py` néven!

```python
#!/usr/bin/env python

import rospy
from std_msgs.msg import Int32  # Message type used in the node

rospy.init_node('publisher')    # Init the node with name "publisher"

pub = rospy.Publisher('publisher_topic', Int32, queue_size=10)

rospy.loginfo("Publisher Python node has started and publishing data on publisher_topic")

rate = rospy.Rate(1)            # 1Hz

count = Int32()                 # Count is now a ROS Int32 type variable that is ready to be published

count.data = 0                  # Initializing count

while not rospy.is_shutdown():  # Run the node until Ctrl-C is pressed

	pub.publish(count)          # Publishing data on topic "publisher_topic"
  
	count.data += 1
	
	rate.sleep()                # The loop runs at 1Hz
```

Tegyük futtathatóvá, figyeljünk a sorvégekre és már indíthatjuk is a node-unkat!

`rosrun bme_ros_tutorials publisher.py`

Nézzük meg a node és topic részleteit a C++ nodehoz hasonlóan!

___

- ## Subscriber

A ROS subsciber adatokat fogad egy vagy több publishertől. Hozzuk létre az első subscriber-ünket C++-ban:

`roscd bme_ros_tutorials`

Hozzuk létre a subscriber.cpp fájlt a src mappában:

`cd src`

`touch subscriber.cpp`

A subscriber.cpp fájl tartalma:  

```cpp
#include "ros/ros.h"
#include "std_msgs/Int32.h" // Message type used in the node

/*
"sub_cb" is the callback method of the subscriber. Argument "msg" contains the received data with type Int32.
*/
void sub_cb(const std_msgs::Int32::ConstPtr& msg)
{
	ROS_INFO("Received data from publisher_topic: [%ld]", (long int)msg->data);
}

int main(int argc, char **argv)
{
	ros::init(argc, argv, "subscriber"); // Init the node with name "subscriber"
	ros::NodeHandle nh;                  // NodeHandle will fully initialze the node
	
    /**
     * The subscribe() call is how you tell ROS that you want to receive messages
     * on a given topic.  This invokes a call to the ROS
     * master node, which keeps a registry of who is publishing and who
     * is subscribing.  Messages are passed to a callback function, here
     * called chatterCallback.  subscribe() returns a Subscriber object that you
     * must hold on to until you want to unsubscribe.  When all copies of the Subscriber
     * object go out of scope, this callback will automatically be unsubscribed from
     * this topic.
     *
     * The second parameter to the subscribe() function is the size of the message
     * queue.  If messages are arriving faster than they are being processed, this
     * is the number of messages that will be buffered up before beginning to throw
     * away the oldest ones.
     */
	ros::Subscriber sub = nh.subscribe("publisher_topic", 10, sub_cb);
	
	ROS_INFO("Subscriber C++ node has started and subscribed to publisher_topic");
    
    /**
     * ros::spin() will enter a loop, pumping callbacks.  With this version, all
     * callbacks will be called from within this thread (the main one).  ros::spin()
     * will exit when Ctrl-C is pressed, or the node is shutdown by the master.
     */
	ros::spin();

	return 0;
}
```

Adjuk hozzá az új node-unkat a CMakeLists.txt fájlhoz:

```cmake
add_executable(subscriber src/subscriber.cpp)
target_link_libraries(subscriber ${catkin_LIBRARIES})
```

Fordítsuk újra a catkin workspace-t, töltsük be a környezetet és indítsuk el az előző publisher és az új subscriber node-ot is!

`rosrun bme_ros_tutorials publisher`  
`rosrun bme_ros_tutorials subscriber`

```console
david@DavidsLenovoX1:~/catkin_ws$ rosrun bme_ros_tutorials subscriber 
[ INFO] [1608743540.153272400]: Subscriber C++ node has started and subscribed to publisher_topic
[ INFO] [1608743573.935493500]: Received data from publisher_topic: [1]
[ INFO] [1608743574.934859200]: Received data from publisher_topic: [2]
[ INFO] [1608743575.934844800]: Received data from publisher_topic: [3]
[ INFO] [1608743576.934547200]: Received data from publisher_topic: [4]
[ INFO] [1608743577.935232600]: Received data from publisher_topic: [5]
...
```

Nézzük meg a `rosnode list` parancsot, látjuk a listában a subscriber és a publisher node-ot is:

```console
david@DavidsLenovoX1:~$ rosnode list
/publisher
/rosout
/subscriber
```

A `rostopic info /publisher_topic` alapján pedig azt is látjuk, hogy a publisher node generálja az adatot a subscriber node pedig fogyasztja:  

```console
david@DavidsLenovoX1:~$ rostopic info /publisher_topic 
Type: std_msgs/Int32

Publishers: 
 * /publisher (http://172.21.233.33:40571/)

Subscribers: 
 * /subscriber (http://172.21.233.33:41967/)
```

Csináljuk meg a Python subscriberünket subscriber.py néven:

```python
#!/usr/bin/env python

import rospy
from std_msgs.msg import Int32 # Message type used in the node

'''
"sub_callback" is the callback method of the subscriber. Argument "msg" contains the received data.
'''
def sub_callback(msg):
	rospy.loginfo("Received data from publisher_topic: %d", msg.data)

rospy.init_node('subscriber_py') # Init the node with name "subscriber_py"

rospy.Subscriber("publisher_topic", Int32, sub_callback, queue_size=10) 

rospy.loginfo("Subscriber_py node has started and subscribed to publisher_topic")

'''
rospy.spin() simply keeps your node from exiting until the node has been shutdown.
Unlike roscpp::spin(), rospy.spin() does not affect the subscriber callback functions,
as those have their own threads.
'''
rospy.spin() 
```

Ezúttal indítsuk el a C++ publisherünket és mind a Python mind a C++ subscriberünket, ehhez már 3 terminálra lesz szükségünk (plusz a roscore)!

`rosrun bme_ros_tutorials publisher`  
`rosrun bme_ros_tutorials subscriber`
`rosrun bme_ros_tutorials subscriber.py`

Nézzük meg a `rostopic info /publisher_topic`-ot:

```console
david@DavidsLenovoX1:~$ rostopic info /publisher_topic 
Type: std_msgs/Int32

Publishers: 
 * /publisher (http://172.21.233.33:36551/)

Subscribers: 
 * /subscriber_py (http://172.21.233.33:43819/)
 * /subscriber (http://172.21.233.33:37199/)
```

Vegyük észre, hogy ezúttal más nevet adtunk a Python subscriber node-nak! Mi történne, ha azonos neve lenne mindkét node-nak?

A másodikként induló node leállítaná a már futó és azonos néven regisztrált node-ot:

```console
[ WARN] [1608744310.401095700]: Shutdown request received.
[ WARN] [1608744310.401328800]: Reason given for shutdown: [[/subscriber] Reason: new node registered with same name]
```

Próbáljuk még ki azt, hogy csak az egyik subscriberünk fut, ilyenkor nincs bejövő adat, hiszen nem fut a publisher node.
A következő paranccsal viszont a parancssorból tudunk megadott topicra adatot küldeni, publisher node futtatása nélkül!

`rostopic pub /publisher_topic std_msgs/Int32 "data: 111" -1`

```console
david@DavidsLenovoX1:~$ rostopic pub /publisher_topic std_msgs/Int32 "data: 111" -1
publishing and latching message for 3.0 seconds
```

A `-1` kapcsolónak köszönhetően csak 1 üzenetet publisholtunk, azonban megtehetjük azt is, hogy folyamatosan publisholunk megadott frekvenciával. Ezt a frekvenciát a rate `-r` kapcsoló és az utána álló szám határozza meg. Például 10 Hz-cel a következőképp publisholhatunk parancssorból:

`rostopic pub /publisher_topic std_msgs/Int32 "data: 111" -r 10`

Ctrl+C-vel tudjuk megszakítani a parancssori publisht ebben az esetben.

Ahogy ebben a példában láttuk a ROS segítségével könnyen megoldható, hogy egy C++ alapú node adatokat adjon át egy Pythonban írt node-nak, sőt nagyobb rendszerek esetén is tetszőlegesen keverhetjük a különböző nyelveken megírt node-jainkat. Ez az egyik hatalmas előnye a ROS-nak és annak, hogy nem egy hatalmas monolitikus alkalmazást fejlesztünk.

___

# WORK IN PROGRESS


```cmake
###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
# include
  ${catkin_INCLUDE_DIRS}
)


add_executable(service_server_node_cpp src/cpp_service_server.cpp)
target_link_libraries(service_server_node_cpp ${catkin_LIBRARIES})

add_executable(service_client_node_cpp src/cpp_service_client.cpp)
target_link_libraries(service_client_node_cpp ${catkin_LIBRARIES})

add_executable(action_server_node_cpp src/cpp_action_server.cpp)
target_link_libraries(action_server_node_cpp ${catkin_LIBRARIES})

add_executable(action_client_node_cpp src/cpp_action_client.cpp)
target_link_libraries(action_client_node_cpp ${catkin_LIBRARIES})
```


- ## rqt

Az rqt egy grafikus tool, ami nagyon hasznos a ROS üzeneteinek megjelenítésére akár táblázatos, akár grafikus formában. Az rqt Python vagy C++ pluginekkel tetszőlegesen kiegészíthető.  

Indítsunk egy ROS mastert és a korábbi  publisher node-unkat.  

Utána egy újabb terminál ablakban indítsuk el az rqt-t az `rqt` paranccsal.  

Az alap pluginek közül az egyik legfontosabb a `Topic Monitor`.  
![alt text][image6]  
A topic monitorban láthatjuk az egyes ROS topicokban közölt adatokat, a topicok adatforgalmát és frekvenciáját.  
![alt text][image7]  
Egy másik hasznos alap plugin a `Plot`.  
![alt text][image8]  
Ezzel grafikusan tudjuk ábrázolni azokat az adatainkat, amik számformátumúak.  
![alt text][image9]  

- ## Launchfile  

ROS node-okat nem csak a `rosrun` paranccsal tudunk indítani. Készíthetünk úgynevezett launchfile-okat. Ezek speciális XML fájlok, ahol egy launchfile-ban tetszőleges számú node-ot indíthatunk, vagy akár más launchfile-okat is elindíthatunk. Ezeket tipikusan egy node launch mappájában tartjuk, de bárhonnan indíthatók.

A launchfile felépítése:

```xml
<?xml version="1.0"?>

<launch>
  <!-- Start other launchfile -->
  <include file="$(find bme_ros_tutorials)/launch/publisher.launch"/>
  <!-- Start a single node -->
  <node name="subscriber" pkg="bme_ros_tutorials" type="subscriber" output ="screen"/>
</launch>
```

- ## Services

- ## Actions

- ## Messages


rosnode list, rostopic list, rostopic info

***
## Turtlesim

rosrun turtlesim turtlesim_node

rosrun turtlesim draw_square 

rosrun turtlesim turtle_teleop_key



### Twist üzenetek

### Keyboard teleop

### Hello World! Első saját ROS node-unk


http://wiki.ros.org/ROS/Introduction

http://wiki.ros.org/ROS/Tutorials