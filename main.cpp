#include <cstdlib>
#include <ctime>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>

namespace fs = std::filesystem;

std::string getTimeNow() {
    std::time_t now = std::time(nullptr);
    std::tm* localTime = std::localtime(&now);

    char output[20];

    std::strftime(output, sizeof(output), "%Y%m%d_%H%M%S", localTime);

    return output;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <directory>" << std::endl;
	return 1;
    }

    const std::string dir = argv[1];
    
    if (!fs::exists(dir) || !fs::is_directory(dir)) {
	std::cerr << "error: directory does not exist or is not a directory" << std::endl;
	return 1;
    }

    std::string timestamp = getTimeNow();
    std::string archiveName = "logs_archive_" + timestamp + ".tar.gz";

    std::string archiveDir = "./archive"; 
    if (!fs::exists(archiveDir)) {
        fs::create_directory(archiveDir);
    }
    
    std::string archivePath = archiveDir + "/" + archiveName;

    std::string cmd = "tar -czf " + archivePath + " -C " + dir + " .";

    int res = system(cmd.c_str());

    if (res != 0) {
        std::cerr << "error: failed to create the archive" << std::endl;
        return 1;
    }
    
    std::ofstream logFile("log.txt", std::ios::app);
    if (!logFile) {
        std::cerr << "error: could not open log file for writing" << std::endl;
	return 1;
    }
        
    logFile << "Archived " << dir << " to " << archivePath << " at " << timestamp << std::endl;
    logFile.close();

    std::cout << "Archive created successfully: " << dir << std::endl;
    return 0;
}
