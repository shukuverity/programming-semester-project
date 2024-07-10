
 int choice;
 do {
     cout << "Choose activity type:\n 1. Sport\n 2.Club/Society\n 3. Done: ";
     cin >> choice;

     if (choice == 1) {
         cout << "Choose sport: ";
         for (size_t i = 0; i < sports.size(); ++i) {
             cout << i + 1 << ". " << sports[i].name << " (" << sports[i].members.size() << "/" << sports[i].max_capacity << ")\n";
         }
         int sport_choice;
         cin >> sport_choice;
         if (sport_choice >= 1 && sport_choice <= sports.size()) {
             if (sports[sport_choice - 1].members.size() < sports[sport_choice - 1].max_capacity) {
                 student.activities.push_back(sports[sport_choice - 1].name);
                 sports[sport_choice - 1].members.push_back(student);
             }
             else {
                 cout << "Sport is at full capacity.\n";
             }
         }
     }
     else if (choice == 2) {
         cout << "Choose club/society: ";
         for (size_t i = 0; i < clubs.size(); ++i) {
             cout << i + 1 << ". " << clubs[i].name << " (" << clubs[i].members.size() << "/" << clubs[i].max_capacity << ")\n";
         }
         int club_choice;
         cin >> club_choice;
         if (club_choice >= 1 && club_choice <= clubs.size()) {
             if (clubs[club_choice - 1].members.size() < clubs[club_choice - 1].max_capacity) {
                 student.activities.push_back(clubs[club_choice - 1].name);
                 clubs[club_choice - 1].members.push_back(student);
             }
             else {
                 cout << "Club/Society is at full capacity.\n";
             }
         }
     }
 } while (choice != 3);

 students.push_back(student);
}
    
