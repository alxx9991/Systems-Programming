#include <stdio.h>

//Replaces '-' with spaces.
void fix_spaces_location_name(char * location) {
    int i = 0;
    while (location[i] != '\0') {
        if (location[i] == '-') {
            location[i] = ' ';
        }
        i ++;
    }
}

//Replace spaces with '-' and ':' with spaces.
void format_timetable_entry(char * entry) {
    int i = 0;
    while (entry[i] != '\0') {
        if (entry[i] == ' ') {
            entry[i] = '-';
        }
        if (entry[i] == ':') {
            entry[i] = ' ';
        }
        i ++;
    }
}

//Check if the specified time is a valid time.
int check_valid_time(int hour, int minute, int second) {
    if (hour > 23 || hour < 0 || minute > 59 || minute < 0 || second > 59 || second < 0) {
        return -1;
    } else {
        return 0;
    }
}

//Compare two times. Returns -1 if time 1 is after time 2, 0 if otherwise.
int time1_before_time2(int hour1, int minute1, int second1, int hour2, int minute2, int second2) {
    if (hour1 > hour2) {
        return -1;
    } else if (hour1 < hour2) {
        return 0;
    } else {
        if (minute1 > minute2) {
            return -1;
        } else if (minute1 < minute2) {
            return 0;
        } else {
            if (second1 > second2) {
                return -1;
            } else {
                return 0;
            }
        }
    }
}

//Compare two strings. Return 0 if equal, -1 if not.
int string_equals(char* string1, char* string2) {
    int i = 0;
    while (string1[i] != '\0') {
        if (string1[i] != string2[i]) {
            return -1;
        }
        i ++;
    }
    if (string1[i] != string2[i]) {
        return -1;
    }
    return 0;
}

int main(int argc, char ** argv) {
    if (argc != 4) {
        printf("Please provide <source> <destination> <time> as command line arguments\n");
        return -1;
    }

    char * user_source = argv[1];
    char * user_destination = argv[2];
    char * user_time = argv[3];
    
    format_timetable_entry(user_time);

    int user_hour;
    int user_minute;
    int user_second;
    
    int user_sscanf_ret = sscanf(user_time, "%d %d %d", &user_hour, &user_second, &user_minute);
    
    if (user_sscanf_ret != 3) {
        printf("Failed to format user time \"%s\"\n", user_time);
        return -1;
    }

    if(check_valid_time(user_hour, user_minute, user_second) != 0) {
        printf("The user time \"%d:%d:%d\" is invalid.\n", user_hour, user_second, user_minute);
        return -1;
    }
    
    //printf("User source: %s\nUser destination: %s\nUser time: %s\n\n", user_source,user_destination, user_time);
    //printf("User hour: %d\nUser minute: %d\nUser second: %d\n\n", user_hour, user_second, user_minute);
    
    int entries = 0;
    int valid_entries = 0;
    int found_train = 0;

    int next_day = 0;
    int previous_day_hour = 0;

    while(1) {
        char input[4096];
        char * ret = fgets(input, 4096, stdin);

        if (!ret) {
            break;
        }

        entries ++;

        format_timetable_entry(input);

        char source[100];
        char destination[100];
        int hour;
        int minute;
        int second;
        int sscanf_ret = sscanf(input, "%s %s %d %d %d", source, destination, &hour, &minute, &second);
        
        if (sscanf_ret != 5) {
            continue;
        }
        
        if (check_valid_time(hour, minute, second) != 0) {
            continue;
        }
        
        if (hour < previous_day_hour) {
            next_day ++;
        }

        previous_day_hour = hour;

        valid_entries ++;

        fix_spaces_location_name(source);
        fix_spaces_location_name(destination);
        
        //printf("source: %s\ndesintation: %s\nhour: %d\nminute:%d\nsecond:%d\n", source, destination, hour, minute, second);
        if (string_equals(user_source, source) == 0 && string_equals(user_destination, destination) == 0) {
            if((time1_before_time2(hour, user_hour, minute, user_minute, second, user_second) || next_day > 0) && found_train == 0) {
                printf("The next train to %s from %s departs at %02d:%02d:%02d.\n", destination, source, hour, minute, second);
                found_train = 1;
            }
        }

    }

    if (entries == 0) {
        printf("No timetable to process");
        return -1;
    }

    if (found_train == 0) {
        printf("No suitable trains can be found\n");
    }

    printf("Scanned %d valid entries out of %d total entries.\n", valid_entries, entries);
    

    return 0;
}




