#pragma once

const char LOGIN_PAGE[] =
R"(  _                     _        
 | |     ___   __ _    (_)  _ _  
 | |__  / _ \ / _` |   | | | ' \ 
 |____| \___/ \__, |   |_| |_||_|
              |___/              

 Enter your credentials in the following format:
   <username>
   <password>

 -> )";

const char TYPE_PARTIAL[] =
R"(
 What are you going to use Vega Taxi App for?

   [1] Client
   [2] Driver

 -> )";

const char REGISTER_LOGO_PARTIAL[] =
R"(  ____            _     _            
 |  _ \ ___  __ _(_)___| |_ ___ _ __ 
 | |_) / _ \/ _` | / __| __/ _ \ '__|
 |  _ <  __/ (_| | \__ \ ||  __/ |   
 |_| \_\___|\__, |_|___/\__\___|_|   
            |___/                    )";

const char REGISTER_CLIENT_PARTIAL[] = R"(
 Enter your credentials in the following format:
   <username>
   <firstName>
   <lastName>
   <password>

 -> )";

const char REGISTER_DRIVER_PARTIAL[] = R"(
 Enter your credentials in the following format:
   <username>
   <firstName>
   <lastName>
   <password>
   <carNumber>
   <phoneNumber>

 -> )";

const char EXIT_VIEW[] = R"(
     ,-`-.                                       
   ,' .___;      _____                             
  /_ ,'@@,-.    /  ___| 
  (C`____ -'    \ `--.  ___  ___   _   _  ___  _   _  
   \ `--' ;      `--. \/ _ \/ _ \ | | | |/ _ \| | | | 
    ``:`:'      /\__/ /  __/  __/ | |_| | (_) | |_| |  
   .-`  '--.    \____/ \___|\___|  \__, |\___/ \__,_|
  ( /7   \7 )                       __/ |             
   \\i--._|/                       |___/             
  (,-,)   |      ___  ___   ___  _ __         
  ,--:_.  /     / __|/ _ \ / _ \| '_ \
 (  ..__,/      \__ \ (_) | (_) | | | |     
  `-' ;  ``.    |___/\___/ \___/|_| |_|
      `---`
)";

const char ORDER_PAGE[] = 
R"(   ___          _           
  / _ \ _ __ __| | ___ _ __ 
 | | | | '__/ _` |/ _ \ '__|
 | |_| | | | (_| |  __/ |   
  \___/|_|  \__,_|\___|_|   

 Enter data in the following format:
   <current address>
   <current coordinates>
   <destination address>
   <destination coordinates>
   <passengers count>

 -> )";

const char ADD_MONEY_PAGE[] =
R"(     _       _     _                                    
    / \   __| | __| |  _ __ ___   ___  _ __   ___ _   _ 
   / _ \ / _` |/ _` | | '_ ` _ \ / _ \| '_ \ / _ \ | | |
  / ___ \ (_| | (_| | | | | | | | (_) | | | |  __/ |_| |
 /_/   \_\__,_|\__,_| |_| |_| |_|\___/|_| |_|\___|\__, |
                                                  |___/ 
 Enter amount you want to deposit (€) -> )";

const char CHECK_MESSAGES_PAGE[] =
R"(  __  __                                     
 |  \/  | ___  ___ ___  __ _  __ _  ___  ___ 
 | |\/| |/ _ \/ __/ __|/ _` |/ _` |/ _ \/ __|
 | |  | |  __/\__ \__ \ (_| | (_| |  __/\__ \
 |_|  |_|\___||___/___/\__,_|\__, |\___||___/
                             |___/           
)";