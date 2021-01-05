#include <iostream>
#include <locale>
#include <memory>

class DatabaseManager{
	public:
		DatabaseManager(std::string connectionString);
		~DatabaseManager();
		void CreateTable(std::string createTableQuery);
		std::string ReadData(std::string readDataQuery);
		void Update(std::string updateQuery);
		void Delete(std::string deleteQuery);
};

DatabaseManager::DatabaseManager(std::string connectionString){
	std::cout << "Conneting to database: " << connectionString << std::endl;
}

void DatabaseManager::CreateTable(std::string createTableQuery){
	std::cout << "Creating table..." << std::endl;
	std::cout << "CreateTableQuery: " << createTableQuery << std::endl;
}

std::string DatabaseManager::ReadData(std::string readDataQuery){
	std::cout << "Reading data..." << std::endl;
	return "Some readed values here";
}

void DatabaseManager::Update(std::string updateQuery){
	std::cout << "Updating data..." << std::endl;
}

void DatabaseManager::Delete(std::string deleteQuery){
	std::cout << "Deleting data..." << std::endl;
}

DatabaseManager::~DatabaseManager(){
	std::cout << "Closing connection to database ..." << std::endl;
}

class DatabaseClient{
	private:
		std::string connectionString;

		// Item 14: prohibit copying
		DatabaseClient(const DatabaseClient &dbClient);
		DatabaseClient& operator=(const DatabaseClient &dbClient);

	public:
		DatabaseClient(std::string connString);
		void CreateTable(std::string createTableQuery);
		std::string Read(std::string readDataQuery);
		void Update(std::string updateQuery);
		void Delete(std::string deleteQuery);
};

DatabaseClient::DatabaseClient(std::string connString) : connectionString(connString){}

void DatabaseClient::CreateTable(std::string createTableQuery){
	// Item 13: use object to manage resources
	std::auto_ptr<DatabaseManager> dbManager (new DatabaseManager(connectionString));
	dbManager->CreateTable(createTableQuery);
}

std::string DatabaseClient::Read(std::string readDataQuery){
	// Item 13: use object to manage resources
	std::auto_ptr<DatabaseManager> dbManager (new DatabaseManager(connectionString));
	return dbManager->ReadData(readDataQuery);
}

void DatabaseClient::Update(std::string updateQuery){
	// Item 13: use object to manage resources
	std::auto_ptr<DatabaseManager> dbManager (new DatabaseManager(connectionString));
	dbManager->Update(updateQuery);
}

void DatabaseClient::Delete(std::string deleteQuery){
	// Item 13: use object to manage resources
	std::auto_ptr<DatabaseManager> dbManager (new DatabaseManager(connectionString));
	dbManager->Delete(deleteQuery);
}

int main(void){

	DatabaseClient dbClient("Data Source=c:\\mydb.db;Version=3;UseUTF16Encoding=True;");
	dbClient.CreateTable("CREATE TABLE Sample_Tweets(user_id = TEXT, screen_name = TEXT, text = TEXT;");

	std::cout << std::endl;

	std::string returnedData = dbClient.Read("SELECT * FROM Sample_Tweets;");
	std::cout << returnedData << std::endl;

	std::cout << std::endl;

	dbClient.Update("UPDATE Sample_Tweets SET user_id = 10;");

	std::cout << std::endl;

	dbClient.Delete("DELETE FROM Sample_Tweets WHERE user_id = 10;");


	// Here the compiler will complain
	//DatabaseClient secondDbClient = dbClient;


	return 0;
}





