class Logger {
private:
    // Map to save the message and it's current timestamp
    unordered_map<string, int> text_time;
    // TIMEOUT constant to wait time
    const int TIMEOUT = 10;

public:
    Logger() {
        // Empty constructor, text_time initilices automatically.
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        // Check if the message is in the text_time map and doesn't expired
        if (text_time.find(message) != text_time.end() && text_time[message] > timestamp) {
            return false;
        }

        // Update the timestamp or register if this is a new text (first seen)
        text_time[message] = timestamp + TIMEOUT;
        return true;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger* obj = new Logger();
 * bool param_1 = obj->shouldPrintMessage(timestamp,message);
 */
