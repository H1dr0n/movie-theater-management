void customer()
{
    printf("\t\t\t\tYou are in Customer Mode.\n\n");
    printf("\t\t\t\t1. Sign up\n");
    printf("\t\t\t\t2. Log in\n");
    printf("\t\t\t\t3. Browse movies\n");
    printf("\t\t\t\t4. Logout\n");

    printf("\t\t\t\tEnter your choice: ");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1: system("cls"); signup(); break;

        case 2: system("cls"); login(); break;

        case 3: system("cls"); browse_movies(); break;

        case 4: system("cls"); welcome(); break;

        case 5: system("cls"); TestRead(); break;

        case 6: system("cls"); testRead(); break;
    }
}

void signup()
{
    fsu = fopen("userinfo.txt","a+");
    if(getSignup()==1)
    {
        fseek(fsu,0,SEEK_END);
        fwrite(&b,sizeof(b),1,fsu);
        fclose(fsu);
    }

    fli = fopen("logininfo.txt","a+");
    if(getLogin()==1)
    {
        fseek(fli,0,SEEK_END);
        fwrite(&c,sizeof(c),1,fli);
        fclose(fli);

        printf("\t\t\t\tYou've succesfully created an account. Press ENTER to Log in...");
    }
    getch(); //customer();
    login();
}

void login()
{
    char u_name[20], p_word[17];

    printf("\t\t\t\tEnter Username:");
    scanf("%s",u_name); printf("%s\n",u_name);
    printf("\t\t\t\tEnter Password:");
    scanf("%s",p_word); printf("%s\n",p_word);

    fli = fopen("logininfo.txt","r");
    //rewind(fli);
    while(fread(&c,sizeof(c),1,fli)==1)
    {   
        count=0;
        printf("in while loop %s %s\n",c.username,c.password);
        if(((strcmp(c.username,u_name)==0)) && ((strcmp(c.password,p_word)==0)))
        {
            system("cls");
            fclose(fli); count++;
            strcpy(uname,c.username);
            in_login();
        }
        /*printf("%s ",c.username);
        printf("%s ",c.password);*/
    }
    if(count==0)
    {
            
        system("cls"); 
        fclose(fli);
        printf("\t\t\t\tYou've entered invalid log in information.\n");
        login();
    }
}

void in_login()
{
    printf("\t\t\t\t1. Browse Movies to buy.\n");
    printf("\t\t\t\t2. Your Movie list.\n");
    printf("\t\t\t\t3. Log out\n\n");

    printf("\t\t\t\tEnter your choice: ");
    scanf("%d",&choice);

    switch(choice)
    {
        case 1: system("cls"); browseMovToB(); break;

        case 2: system("cls"); ur_movies(); break;

        case 3: system("cls"); customer(); break;

        default: system("cls"); printf("\t\t\t\tinvalid choice. try again\n"); in_login(); break;
    }
}

int getSignup()
{
    printf("\t\t\t\tEnter First Name:");
    scanf("%s",b.Fname);
    fflush(stdin);
    printf("\t\t\t\tEnter Last Name:");
    scanf("%s",b.Lname);
    fflush(stdin);

    return 1;
}

int getLogin()
{
    printf("\t\t\t\tEnter Username:");
    scanf("%s",c.username);
    fflush(stdin);
    printf("\t\t\t\tEnter Password:");
    scanf("%s",c.password);
    fflush(stdin);

    return 1;
}

void TestRead()
{
    fsu = fopen("userinfo.txt","r");

    while(fread(&b,sizeof(b),1,fsu)==1)
    {
        printf("%s ",b.Fname);
        printf("%s ",b.Lname);
    }

    fclose(fsu);

    printf("\n\n\t\t\t\tEnter any key to return to Customer mode... ");
    getch();
    system("cls");
    customer();
}

void testRead()
{
    fli = fopen("logininfo.txt","r");
    while(fread(&c,sizeof(c),1,fli)==1)
    {
        printf("%s ",c.username);
        printf("%s ",c.password);
    }
    fclose(fli);


    printf("\n\n\t\t\t\tEnter any key to return to Customer mode... ");
    getch();
    system("cls");
    customer();
}

void browseMovToB()
{   
    int ticket;
    count=0;

    fp = fopen("movies.txt","r");

    rewind(fp);
    while(fread(&a,sizeof(a),1,fp)==1)
    {
        printf("%d ",a.id);
        printf("%s ",a.movName);
        printf("%s ",a.date);
        printf("%s ",a.time);

        printf("\n");
    }
    //fclose(fp);

    printf("\n\n\t\t\t\tEnter movie id to buy ticket: ");
    scanf("%d",&ticket);

    rewind(fp);

    while(fread(&a,sizeof(a),1,fp)==1)
    {
        if(ticket==a.id)
        {
            printf("Movie id = %d is avilable.\n",ticket);

            //storing movie information in another struct to show them in ur_movies() function
            d.id = a.id;
            strcpy(d.username,uname);
            strcpy(d.movName,a.movName);
            strcpy(d.date,a.date);
            strcpy(d.time,a.time);

            fclose(fp);
            count++;
            break;
        }
    }
    if(count==0)
    {
        printf("Movie id = %d is not avilable.\n",ticket); fclose(fp);
        browseMovToB();
    }
    else if(count>0)
    {
        printf("\nDo you want to buy ticket for this movie? (Y/N): ");
        if(getch()=='y')
        {
            buyTicket();
        }
        else
        {
            printf("\nPress \"Y\" to search for another movie to buy or press \"Enter\" to go back to Customer mode: ");

            if(getch()=='y')
                browseMovToB();
            else 
                customer();
        }
    }
   

}


void ur_movies()
{
    urm = fopen("ur_movies.txt","r");
    
    while(fread(&d,sizeof(d),1,urm)==1)
    {
        if((!(strcmp(d.username,uname))))
        {
            printf("Quantity = %d\n",d.quatity);
            printf("username = %s\n",d.username);
            printf("id = %d\n",d.id);
            printf("movname = %s\n",d.movName);
            printf("date = %s\n",d.date);
            printf("time = %s\n",d.time);
        }
        printf("\n");
    }
    fclose(urm);

    printf("Y to return to customer mode: ");
    getch(); login();
}

void buyTicket()
{
    printf("Enter how many tickets you want to buy for movie \"%s\": ",d.movName);
    scanf("%d",&d.quatity);

    printf("Quantity = %d\n",d.quatity);
    printf("username = %s\n",d.username);
    printf("id = %d\n",d.id);
    printf("movname = %s\n",d.movName);
    printf("date = %s\n",d.date);
    printf("time = %s\n",d.time);

    urm = fopen("ur_movies.txt","a+");
    fseek(urm,0,SEEK_END);
    fwrite(&d,sizeof(d),1,urm);
    fclose(urm);

    printf("\nDo you want to buy another movie ticket (Y/N): ");
        if(getch()=='y')
        {
            browseMovToB();
        }
        else
        {
            printf("\nPress \"Y\" to see your movie list or press \"Enter\" to go back to Customer mode: ");

            if(getch()=='y')
               ur_movies();
            else 
                customer();
        }
}