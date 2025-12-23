# RideShare Manager

A command-line vehicle sharing and carpooling management system written in C that connects vehicle owners with users looking for rides.

## Overview

RideShare Manager is a console-based application that facilitates ride-sharing by allowing vehicle owners to register their vehicles with route details and users to search for available rides based on their travel requirements.

## Features

1. **Vehicle Owner Registration**
   - Register as a vehicle owner
   - Provide vehicle details including route, vehicle type, and travel date
   - Data stored persistently in CSV format

2. **User Registration**
   - Simple user registration system
   - Allows users to register before searching for rides

3. **Display Available Vehicles**
   - View all registered vehicles with complete details
   - Shows owner information, routes, vehicle types, and dates

4. **Search by Route and Date**
   - Filter vehicles by specific start point, end point, and date
   - Get exact matches for your travel needs

5. **Luxury Vehicle Filter**
   - Display owners with luxury vehicles
   - Special category for premium ride options

## Data Storage

The program uses CSV files to store owner and vehicle information:
- `owner_data.csv` - Contains vehicle owner details

**CSV Format:**
```
owner_name, owner_contact, start_point, end_point, vehicle_type, date
```

## Compilation

To compile the program using GCC:

```bash
gcc final_project.c -o rideshare.exe
```

Or use the VS Code build task (C/C++: gcc.exe build active file)

## Usage

1. Run the compiled executable:
   ```bash
   ./rideshare.exe
   ```

2. Select from the menu options:
   - **1** - Register as Vehicle owner
   - **2** - Register as User
   - **3** - Display available vehicles
   - **4** - List Vehicles by route and date
   - **5** - Display owners with luxury vehicles
   - **6** - Exit

3. Follow the on-screen prompts to enter required information

## Example Usage

### Registering a Vehicle Owner:
```
Select an option: 1
Register as a vehicle owner
Please enter your name: John
Please enter your mobile number: 9876543210
Please enter your start point: Bangalore
Please enter your end point: Mysore
Please enter registered vehicle's Type: luxury
Please enter date: 25-12-2025
```

### Searching for Vehicles:
```
Select an option: 4
Enter start point: Bangalore
Enter end point: Mysore
Enter date (DD-MM-YY): 25-12-2025
```

## Requirements

- GCC compiler (MinGW for Windows)
- C standard library
- File system access for CSV storage

## File Structure

```
C_prog(DSA)/
├── final_project.c      # Main source code
├── owner_data.csv       # Vehicle owner data
└── README.md           # This file
```

## Known Limitations

- Menu loop exits on option 4 (design issue in do-while condition)
- Limited input validation
- No newline character in CSV file writing
- Fixed CSV file paths (hardcoded for specific user directory)

## Future Enhancements

- Add booking functionality
- Implement user authentication
- Add vehicle capacity management
- Include pricing calculations
- Add ride history tracking
- Improve input validation and error handling
- Make file paths configurable

## Author

Created as part of DSA coursework

## License

Educational project - Free to use and modify
