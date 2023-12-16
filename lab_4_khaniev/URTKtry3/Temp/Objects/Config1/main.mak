SHELL := cmd.exe
CYGWIN=nontsec
export PATH := C:\Program Files (x86)\Common Files\Oracle\Java\javapath;C:\Windows\system32;C:\Windows;C:\Windows\System32\Wbem;C:\Windows\System32\WindowsPowerShell\v1.0\;C:\Program Files (x86)\NVIDIA Corporation\PhysX\Common;C:\Program Files\NVIDIA Corporation\NVIDIA NvDLISR;C:\Program Files\Git\cmd;C:\Program Files\PuTTY\;C:\Program Files (x86)\Paragon Software\LinuxFS for Windows\;C:\Users\user\AppData\Local\Programs\Python\Python39\Scripts\;C:\Users\user\AppData\Local\Programs\Python\Python39\;C:\Users\user\AppData\Local\Programs\Python\Python310\Scripts\;C:\Users\user\AppData\Local\Programs\Python\Python310\;C:\Users\user\AppData\Local\Microsoft\WindowsApps;C:\Users\user\AppData\Local\Programs\Microsoft VS Code\bin;C:\Program Files\msys64\mingw64\bin;C:\Program Files (x86)\Common Files\Hilscher GmbH\TLRDecode;C:\Users\user\AppData\Local\Programs\Python\Python39\Scripts\;C:\Users\user\AppData\Local\Programs\Python\Python39\;C:\Users\user\AppData\Local\Programs\Python\Python310\Scripts\;C:\Users\user\AppData\Local\Programs\Python\Python310\;C:\Users\user\AppData\Local\Microsoft\WindowsApps;C:\Users\user\AppData\Local\Programs\Microsoft VS Code\bin;C:\Program Files\msys64\mingw64\bin;C:\Program Files (x86)\Common Files\Hilscher GmbH\TLRDecode;D:\Programs\BandR49\AS49\Bin-en\4.9;D:\Programs\BandR49\AS49\Bin-en\4.8;D:\Programs\BandR49\AS49\Bin-en\4.7;D:\Programs\BandR49\AS49\Bin-en\4.6;D:\Programs\BandR49\AS49\Bin-en\4.5;D:\Programs\BandR49\AS49\Bin-en\4.4;D:\Programs\BandR49\AS49\Bin-en\4.3;D:\Programs\BandR49\AS49\Bin-en\4.2;D:\Programs\BandR49\AS49\Bin-en\4.1;D:\Programs\BandR49\AS49\Bin-en\4.0;D:\Programs\BandR49\AS49\Bin-en
export AS_BUILD_MODE := BuildAndTransfer
export AS_VERSION := 4.9.2.46
export AS_WORKINGVERSION := 4.9
export AS_COMPANY_NAME :=  
export AS_USER_NAME := user
export AS_PATH := D:/Programs/BandR49/AS49
export AS_BIN_PATH := D:/Programs/BandR49/AS49/Bin-en
export AS_PROJECT_PATH := D:/govno/URTK_sim-main/URTKtry3
export AS_PROJECT_NAME := URTKtry3
export AS_SYSTEM_PATH := D:/Programs/BandR49/AS/System
export AS_VC_PATH := D:/Programs/BandR49/AS49/AS/VC
export AS_TEMP_PATH := D:/govno/URTK_sim-main/URTKtry3/Temp
export AS_CONFIGURATION := Config1
export AS_BINARIES_PATH := D:/govno/URTK_sim-main/URTKtry3/Binaries
export AS_GNU_INST_PATH := D:/Programs/BandR49/AS49/AS/GnuInst/V4.1.2
export AS_GNU_BIN_PATH := D:/Programs/BandR49/AS49/AS/GnuInst/V4.1.2/4.9/bin
export AS_GNU_INST_PATH_SUB_MAKE := D:/Programs/BandR49/AS49/AS/GnuInst/V4.1.2
export AS_GNU_BIN_PATH_SUB_MAKE := D:/Programs/BandR49/AS49/AS/GnuInst/V4.1.2/4.9/bin
export AS_INSTALL_PATH := D:/Programs/BandR49/AS49
export WIN32_AS_PATH := "D:\Programs\BandR49\AS49"
export WIN32_AS_BIN_PATH := "D:\Programs\BandR49\AS49\Bin-en"
export WIN32_AS_PROJECT_PATH := "D:\govno\URTK_sim-main\URTKtry3"
export WIN32_AS_SYSTEM_PATH := "D:\Programs\BandR49\AS\System"
export WIN32_AS_VC_PATH := "D:\Programs\BandR49\AS49\AS\VC"
export WIN32_AS_TEMP_PATH := "D:\govno\URTK_sim-main\URTKtry3\Temp"
export WIN32_AS_BINARIES_PATH := "D:\govno\URTK_sim-main\URTKtry3\Binaries"
export WIN32_AS_GNU_INST_PATH := "D:\Programs\BandR49\AS49\AS\GnuInst\V4.1.2"
export WIN32_AS_GNU_BIN_PATH := "$(WIN32_AS_GNU_INST_PATH)\\bin" 
export WIN32_AS_INSTALL_PATH := "D:\Programs\BandR49\AS49"

.suffixes:

ProjectMakeFile:

	@'$(AS_BIN_PATH)/4.9/BR.AS.AnalyseProject.exe' '$(AS_PROJECT_PATH)/URTKtry3.apj' -t '$(AS_TEMP_PATH)' -c '$(AS_CONFIGURATION)' -o '$(AS_BINARIES_PATH)'   -sfas -buildMode 'BuildAndTransfer'   

