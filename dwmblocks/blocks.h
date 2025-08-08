static const Block blocks[] = {
    /*Icon*/  /*Command*/  /*Interval*/ /*Signal*/

    // Звук: mute ↔ громкость
    {"┇  ",  "amixer get Master | awk -F'[][]' '/Left:/ { \
                if ($4==\"off\") printf \"  Mute\"; \
                else printf \" %s\", $2 }'",                                            5,          0},

    // Язык
    {"  ", "xkblayout-state print %s | awk '{ \
      l=tolower($0); \
      if (l==\"us\") printf \"[EN]\"; \
      else printf \"[%s]\", toupper($0) \
    }'", 0, 1 },    
    
    // RAM
    {"  ",  "free -m | awk 'NR==2{printf \"%3.0f%%\", $3/$2*100}'",                                                 5,          0},

    // Battery
    {"  ",  "cat /sys/class/power_supply/BAT0/capacity | awk '{print $1\"%\"}'",                                   15,         0},

    // Wi-Fi
    {"  ",  "nmcli radio wifi | awk '{if ($1==\"enabled\") print \"on\"; else print \"off\"}'",            10,         0},

    // Bluetooth
    {"  ",  "bash -c 'bluetoothctl info 90:7A:58:EA:C2:7A | grep -q \"Connected: yes\" && echo on || echo off'", 10, 0},
    
    // Погода Khabarovsk
    {"  ",  "curl -s 'wttr.in/Khabarovsk?format=%t'",                                                              300,        0},

    // Дата и время
    {"  ",  "date '+%d.%m'",                                                                                       60,         0},
    {"  ",  "date '+%H:%M'",                                                                                     5,          0},
};

// возвращаем трёхчленный разделитель между блоками
static char delim[] = "  ┇  ";
static unsigned int delimLen = 5;