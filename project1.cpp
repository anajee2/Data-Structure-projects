#Problem 1:

double n;
char response;
cout<<"Enter a number of seconds: ";
cin>>n;
cout<<"Menu options: " << endl << " (M)inutes" << endl << " (H)ours" << endl << " (D)ays";
cout<<endl << "Select the conversion format M/H/D and enter it here: ";
cin>>response;

switch(response){
     case 'M':
          cout<<"The number of seconds entered is: "<< n/60 << " Minutes";
          break;
     case 'H':
          cout<<"The number of seconds entered is: "<< n/3600 << " Hours";
          break;
     case 'D':
          cout<<"The number of seconds entered is: "<< n/86400 << " Days";
          break;

}

#Problem 2

vector<string> studentNames;
string temp;

cout<<"Enter student 1 name:";
cin>>temp;
studentNames.push_back(temp);

cout<<"Enter student 2 name:";
cin>>temp;
studentNames.push_back(temp);

cout<<"Enter student 3 name:";
cin>>temp;
studentNames.push_back(temp);

cout<<"Enter student 4 name:";
cin>>temp;
studentNames.push_back(temp);

sort(studentNames.begin(), studentNames.end());

for(int i = 0; i < 4; i++) {
    cout << studentNames[i] << endl;
}




