#include <windows.h>
#include "process.h"
#include "structs.h"
#include "Order.h"
#include "Administrator.h"
#include "Client.h"
#include "Catalogue.h"
#include "Transport.h"

using namespace std;

int main()
{
	CountriesStruct c[10] = {
		CountriesStruct{1, "Brazil", 4000},
		CountriesStruct{2, "Cyprus", 3500},
		CountriesStruct{3, "Egypt", 2000},
		CountriesStruct{4, "Georgia", 6000},
		CountriesStruct{5, "Italy", 5000},
		CountriesStruct{6, "Japan", 9000},
		CountriesStruct{7, "New Zealand", 5500},
		CountriesStruct{8, "Sweden", 6500},
		CountriesStruct{9, "Australia", 8000},
		CountriesStruct{10, "France", 7500}
	};
	PackageStruct p[3] = {
		PackageStruct{1, "Crowne Plaza", 14, "HcAi", 10000},
		PackageStruct{2, "Hotel Elite", 10, "Ai", 7000},
		PackageStruct{3, "The New View", 8, "RO", 3000},
	};
	VehicleStruct v[3] = {
		VehicleStruct{1, "Bus", 500},
		VehicleStruct{2, "Airplane", 1000},
		VehicleStruct{3, "Boat", 1500},
	};
	Package package = Package(p, size(p));
	Countries countries = Countries(c, size(c));
	Vehicle vehicle = Vehicle(v, size(v));
	Catalogue catalogue(countries, package);
	Transport transport[3]{
		Transport{"Bus"},
		Transport{"Airplane"},
		Transport{"Boat"},
	};
	Vehicle* vehicleAbout = new Vehicle();

	int number_menu = 0, number_admin = 0, number_wagem = 0, number_country, number_package, number_order, number_vehicle;
	string name, surname, password, pasp_id, choice_status, choice;

	cout << "Welcome to the Join Up Tour Agencies network. Best price, guaranteed." << endl;
	cout << "Enter your name, surname and password." << endl;

	cout << "Name: ";
	cin >> name;
	cout << "Surname: ";
	cin >> surname;
	cout << "Password: ";
	cin >> password;

	Client client(name, surname, password, package, countries);
	Order ord(client.getFullName(), pasp_id);

	cout << endl << "You have been logged. " << client.getFullName() << endl << endl;
	while (number_menu != EXIT)
	{
		cout << endl << "Please, choose the option:" << endl;
		cout << CATALOGUE << ". Show catalogue" << endl;
		cout << MY_BALANCE << ". Show my balance" << endl;
		cout << CHOICE_VEHICLE << ". Choice vehicle" << endl;
		cout << CHOICE_COUNTRIES << ". Choice countries" << endl;
		cout << CHOICE_PACKAGES << ". Choice packages" << endl;
		cout << SHOW_CHOICES_VEHICLE << ". Selected vehicle" << endl;
		cout << SHOW_CHOICES_COUNTRIES << ". Selected country" << endl;
		cout << SHOW_CHOICES_PACKAGES << ". Selected packages" << endl;
		cout << CREATE_ORDER << ". Create order" << endl;
		cout << SHOW_ORDER_CLIENT << ". Show order" << endl;
		if (client.is_admin() || client.is_better_admin())
		{
			cout << ADMIN_PANEL << ". Admin panel" << endl;
		}
		cout << RE_ENTER_PASSWORD << ". Re-enter password" << endl;
		cout << EXIT << ". Exit" << endl << endl;

		cout << "Enter choice: ";
		cin >> number_menu;

		if (number_menu == CATALOGUE)
		{
			catalogue.showCountries();
			catalogue.showPackage();
		}
		else if (number_menu == MY_BALANCE)
		{
			cout << "Your Balance: " << client.getMoney() << " UAH" << endl;
		}
		else if (number_menu == CHOICE_VEHICLE)
		{
			cout << "Enter vehicle number: ";
			cin >> number_vehicle;
			VehicleStruct vehicle_client = client.getVehicleByNumber(number_vehicle);
			cout << endl << "You choice: " << endl;

			vehicle_client.vehicle_selected();
			client.setChoiceClientVehicle(vehicle_client);
			
			if (number_vehicle == 1) {
				Vehicle* bus = new Bus();
				vehicleAbout = &transport[1];
				vehicleAbout->aboutVehicle();
			}
			else if (number_vehicle == 2) {
				t(*vehicleAbout);
				t(transport[2]);
				Vehicle* airplane = new Airplane();
				t(*airplane);
			}
			else if (number_vehicle == 3) {
				vehicleAbout = &transport[3];
				vehicleAbout->aboutVehicle();
				Boat boat;
				vehicleAbout = (Vehicle*)&boat;
				vehicleAbout->aboutVehicle();
				vehicleAbout = (Vehicle*)&transport[2];
				vehicleAbout->aboutVehicle();

				/*
				vehicleAbout = new Boat();
				vehicleAbout->aboutVehicle();
				delete vehicleAbout;
				*/
			}
		}
		else if (number_menu == CHOICE_COUNTRIES)
		{
			cout << "Enter country number: ";
			cin >> number_country;
			VehicleStruct vehicle_client = client.getVehicleByNumber(number_country);
			cout << endl << "You choice: " << endl;

			vehicle_client.vehicle_selected();
			client.setChoiceClientVehicle(vehicle_client);
		}
		else if (number_menu == CHOICE_PACKAGES)
		{
			cout << "Enter package number: ";
			cin >> number_package;
			PackageStruct package_client = client.getPackageByNumber(number_package);
			cout << endl << "You choice: " << endl;

			package_client.service_package();
			client.setChoiceClientPackage(package_client);
		}
		else if (number_menu == SHOW_CHOICES_VEHICLE)
		{
			client.getChoiceClientVehicle().vehicle_selected();
		}
		else if (number_menu == SHOW_CHOICES_COUNTRIES)
		{
			client.getChoiceClientCountries().country_selected();
		}
		else if (number_menu == SHOW_CHOICES_PACKAGES)
		{
			client.getChoiceClientPackage().service_package();
		}
		else if (number_menu == CREATE_ORDER)
		{
			cout << "Do you want confirm order? (Y/n) ";
			cin >> choice;
			if (choice == "y" || choice == "Y")
			{
				cout << "Please, enter your Pasport ID: ";
				cin >> pasp_id;
				client.setPasportId(pasp_id);

				cout << "..." << endl << endl;

				ord.setCountry(countries);
				ord.setPackage(package);

				Sleep(1000);

				ord.createOrder(
					OrderStruct{
						ord.getOrder().size() + 1,
						client.getChoiceClientCountries(),
						client.getChoiceClientPackage(),
						client.getChoiceClientVehicle(),
						client.getFullName(),
						client.getPasportId(),
						"..."
					}
				);

				cout << "Thank you for the order! If you have any questions, call 000000000." << endl << endl;
				cout << "Your check" << endl << endl;
				ord.getOrder()[ord.getOrder().size() - 1].print_order();
				cout
					<< "UAH " << client.getChoiceClientCountries().price +
					client.getChoiceClientPackage().price
					<< " if accepted, it will be removed from your balance."
					<< endl << endl;
				client.setOrdr(ord);
			}
		}
		else if (number_menu == SHOW_ORDER_CLIENT)
		{
			client.showOrder();
		}
		else if (number_menu == ADMIN_PANEL) {
			if (client.is_admin() || client.is_better_admin())
			{
				Administrator admin(name, surname, password);
				TourAgency agency(&admin);
				EmployeeAgency emple;
				while (number_admin != EXIT_ADMIN)
				{
					cout << "Greetings, " << agency.getFullName() << " Admin" << endl << endl;
					cout << "Please, choose the option:" << endl;
					cout << SHOW_ORDER_ADMIN << ". Show orders" << endl;
					cout << CHANGE_STATUS_APPLICATION << ". Change order status" << endl;
					cout << EXIT_ADMIN << ". Exit admin panel" << endl << endl;

					cout << "Enter choice: ";
					cin >> number_admin;

					if (number_admin == EXIT_ADMIN)
					{
						number_menu = 0;
					}
					else if (number_admin == SHOW_ORDER_ADMIN)
					{
						admin.showOrder(&ord);
					}
					else if (number_admin == CHANGE_STATUS_APPLICATION)
					{
						cout << "Enter number application: ";
						cin >> number_order;
						cout << "Enter status (Aprove, Reject): ";
						cin >> choice_status;
						admin.changeStatus(number_order, choice_status, &client, &ord);
					}
					if (client.is_better_admin())
					{
						cout << ADD_WAGE << ". Add wage for yourself" << endl;
						cout << MEDIUM_WAGE << ". Chek medium wage of you and deafault admin" << endl;
						cout << REDUCE_WAGE << ". Reduce wage" << endl;
						cout << DIF_WAGE << ". Wage difference with default admin" << endl;
						cout << SWAP_WAGE << ". Swap wage" << endl;
						cout << TOP << ". Chek top company" << endl;
						Administrator adm;
						Administrator* void_adm;
						if (number_admin == ADD_WAGE) {
							adm++;
						}
						else if (number_admin == MEDIUM_WAGE) {
							adm + *void_adm;
						}
						else if (number_admin == REDUCE_WAGE) {
							adm--;
						}
						else if (number_admin == DIF_WAGE) {
							adm - *void_adm;
						}
						else if (number_admin == SWAP_WAGE) {
							int lowWage = 4000;
							int highWage = 8000;
							swap_wage<int>(lowWage, highWage);
						}
						else if (number_admin == TOP) {
							cout << "Company top employee" << endl;
							top_employee();
						}
					}
				}
			}
			else
			{
				cout << "You shouldn't have seen it" << endl;
			}
		}
		else if (number_menu == RE_ENTER_PASSWORD)
		{
			cout << "Enter new Password: ";
			cin >> password;
			client.setPassword(password);
		}
	}
}