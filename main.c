#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELD_LENGTH 256
#define DELIMITER ','


char users[100];

char user_name[50];




// int owner_count=0;
// int user_count=0;
void reg_owner();
int reg_user();
int disp_avail_vehicles();
void list_vehicles_by_route_and_date();
void print_luxury_owners();
int main()
{	int option;
	
	do
{
	printf("\n1.Register as Vehicle owner\n2.Register as User\n3.Display available vehicles\n4.List Vehicles by route and date\n5.Display owners with luxury vehicles\n6.Exit\nSelect an option:");
	scanf("%d",&option);
	
	switch (option)
	{
	case 1:
		reg_owner();
		break;
	case 2:
		return reg_user();
		break;
	case 3:
		return disp_avail_vehicles();
		break;
	case 5:
		print_luxury_owners();
		break;
	case 6:
		printf("Thank you for choosing us");
		exit(0);
	case 4:
		list_vehicles_by_route_and_date();
		break;
	case 0:
		printf("Please select a valid option");
		break;
	default:
		printf("Please select a valid option");
		break;
	}
} while (option!=4);




	return 0;
}

void reg_owner(){
	char owner_name[15];
	char owner_contact[15];
	char start_point[25];
	char end_point[25];
	char vehicle_name[25];
	char date[25];
	printf("Register as a vehicle owner\nPlease enter your name:");
	scanf("%s",&owner_name);
	printf("Please enter your mobile number:");
	scanf("%s",&owner_contact);
	printf("Please enter your start point:");
	scanf("%s",&start_point);
	printf("Please enter your end point:");
	scanf("%s",&end_point);
	printf("Please enter registered vehicle's Type:"); 
	scanf("%s",&vehicle_name);
	printf("Please enter date:");
	scanf("%s",&date);
	FILE* f1=fopen("C:\\Users\\Rakesh R K\\C_prog\\owner_data.csv","a+");
	fprintf(f1,"%s,%s,%s,%s,%s,%s",owner_name,owner_contact,start_point,end_point,vehicle_name,date);
	printf("%s has been registerd as an owner\n",owner_name);
	fclose(f1);
	// owner_count+=1;
	// printf("The number of registered vehicles are %d",owner_count);
}
int reg_user(){
	printf("Register as user\nPlease enter your name");
	scanf("%s",&user_name);
	printf("%s has been registered as a user\n",user_name);
	// user_count+=1;
	// users[1]=user_name;
	// printf("%s",users[1]);
	// printf("The number of users are %d",user_count);
}
int disp_avail_vehicles(){
	FILE* f1=fopen("owner_data.csv","r");
	  if (f1== NULL) {
        printf("Failed to open the file.\n");
        return 0;
    }

    char line[MAX_LINE_LENGTH];
    int first_row = 1;  // Flag to indicate if it's the first row

    while (fgets(line, MAX_LINE_LENGTH, f1) != NULL) {
        if (first_row) {
            first_row = 0;  // Set the flag to false after skipping the first row
            continue;       // Skip printing the first row
        }

        char *token = strtok(line, ",");
        while (token != NULL) {
            printf("%s\t", token);
            token = strtok(NULL, ",");
        }
        printf("\n");
    }

    fclose(f1);
}

void list_vehicles_by_route_and_date() {
    char start_point[25];
    char end_point[25];
    char date[11]; // format: YYYY-MM-DD

    printf("Enter start point: ");
    scanf("%24s", start_point);
    printf("Enter end point: ");
    scanf("%24s", end_point);
    printf("Enter date (DD-MM-YY): ");
    scanf("%10s", date);

    FILE *f1 = fopen("owner_data.csv", "r");
    if (f1 == NULL) {
        printf("Failed to open the file.\n");
        return;
    }

    char line[MAX_LINE_LENGTH];
    int first_row = 1;
    int found = 0;

    while (fgets(line, MAX_LINE_LENGTH, f1) != NULL) {
        if (first_row) {
            first_row = 0;
            continue;
        }

        char *token = strtok(line, ",");
        char owner_name[15], owner_contact[15], vehicle_start_point[25], vehicle_end_point[25], vehicle_name[15], vehicle_date[11];
        strcpy(owner_name, token);
        token = strtok(NULL, ",");
        strcpy(owner_contact, token);
        token = strtok(NULL, ",");
        strcpy(vehicle_start_point, token);
        token = strtok(NULL, ",");
        strcpy(vehicle_end_point, token);
        token = strtok(NULL, ",");
        strcpy(vehicle_name, token);
        token = strtok(NULL, ",");
        strcpy(vehicle_date, token);
		token = strtok(NULL, ",");
        if (strcmp(start_point, vehicle_start_point) == 0 && strcmp(end_point, vehicle_end_point) == 0 && strcmp(date, vehicle_date) == 0) {
            printf("%s, %s, %s, %s, %s, %s\n", owner_name, owner_contact, vehicle_start_point, vehicle_end_point, vehicle_name, vehicle_date);
            found = 1;
        }
    }

    if (!found) {
        printf("No vehicles found for the specified route and date.\n");
    }

    fclose(f1);
}

void print_luxury_owners() {
    FILE *f1 = fopen("owner_data.csv", "r");
    if (f1 == NULL) {
        printf("Failed to open the file.\n");
        return;
    }

    char line[MAX_LINE_LENGTH];
    int first_row = 1;

    while (fgets(line, MAX_LINE_LENGTH, f1) != NULL) {
        if (first_row) {
            first_row = 0;
            continue;
        }

        char *token = strtok(line, ",");
        char owner_name[15];
        char vehicle_type[15];
        
        strcpy(owner_name, token);
        
        // Skip the next three columns
        for (int i = 0; i < 3; i++) {
            token = strtok(NULL, ",");
        }
        
        token = strtok(NULL, ",");
        strcpy(vehicle_type, token);

        if (strcmp(vehicle_type, "luxury") == 0) {
            printf("%s\n", owner_name);
        }
    }
fclose(f1);
}
