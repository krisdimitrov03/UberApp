#pragma once

namespace error {
	const char INVALID_OPTION_NUMBER[] = "Invalid option number. Choose one from the menu.";

	const char INVALID_LOGIN[] = "Invalid username or password.";

	const char INVALID_USERNAME[] = "Username must contain only letters, '.' and '_'.";
	const char INVALID_F_NAME[] = "First name must contain only letters.";
	const char INVALID_L_NAME[] = "Last name must contain only letters.";
	const char INVALID_PASSWORD[] = "Password must be at least: 8 chars, 1 upper, 1 digit, 1 special";

	const char USER_ALREADY_LOGGED[] = "";

	const char FILE_NOT_OPENNING[] = "Logging file could not open.";

	const char INVALID_PASSENGERS_COUNT[] = "Passengers must be a maximum of 3.";

	const char ORDER_NOT_FINISHED[] = "You can pay only when order is finished.";
	const char ORDER_CANCEL_FAIL[] = "Order could not be canceled.";
	const char DRIVER_RATE_FAIL[] = "Driver could not be rated.";
	const char ORDER_FINISH_FAIL[] = "Order could not be finished.";
	const char PAYMENT_NOT_ACCEPTED[] = "Payment could not be accepted.";
	const char ADDRESS_CHANGE_FAIL[] = "Address could not be changed.";
}

namespace success {
	const char REGISTERED[] = "Account created successfully.";
	const char ORDER_SUCCESSFUL[] = "Order made. Searching for a taxi...";
	const char DEPOSIT_SUCCESSFUL[] = "Deposit successful.";
	const char ORDER_CANCELED[] = "Order canceled.";
	const char DRIVER_RATE_SUCCESSFUL[] = "Driver rated.";
	const char ORDER_FINISHED[] = "Order finished.";
	const char PAYMENT_ACCEPTED[] = "Payment accepted";
	const char ADDRESS_CHANGED[] = "Address changed.";
}