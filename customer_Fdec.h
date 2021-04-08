struct signup
{
    char Fname[20];
    char Lname[20];
}b;
struct login
{
    char username[20];
    char password[17];
}c;

FILE *fsu, *fli;
int count=0;

void customer();
void signup();
void login();
int getSignup();
int getLogin();
void ur_movie();
void in_login();

void TestRead();
void testRead();