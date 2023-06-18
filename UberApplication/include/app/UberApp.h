#pragma once

namespace globals {
	const char DB_FILE_NAME[] = "db.dat";
}

class UberApp
{
	void readFromFile();
	void saveToFile() const;
public:
	UberApp() = default;
	void run();
};

