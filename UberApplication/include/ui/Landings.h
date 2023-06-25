#pragma once

const char GUEST_LANDING[] = R"(
 You are <Guest> in Vega Taxi App.
 Choose one of the options below:

    [1] Log in
    [2] Register
    [3] Change theme
    [4] Exit

 Enter number: )";

const char CLIENT_LANDING[] = R"(
 Choose one of the options below:

   [1] Order taxi
   [2] Add money
   [3] Log out
   [4] Exit

 Enter number: )";

const char ORDERED_CLIENT_LANDING[] = R"(
 Choose one of the options below:

   [1] Check order
   [2] Cancel order
   [3] Pay
   [4] Add money
   [5] Log out
   [6] Exit

 Enter number: )";

const char DRIVER_LANDING[] = R"(
 Choose one of the options below:

   [1] Change address
   [2] Check messages
   [3] Log out
   [4] Exit

 Enter number: )";

const char DRIVER_IN_ORDER_LANDING[] = R"(
 Choose one of the options below:

   [1] Change address
   [2] Finish order
   [3] Accept payment
   [4] Log out
   [5] Exit

 Enter number: )";