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
}

namespace success {
	const char REGISTERED[] = "Account created successfully.";
}