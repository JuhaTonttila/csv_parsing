#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>


class CSVLine {
    // Extract items from a line in csv file into a vector "buff". For more specific applications add some other functions...
    
    private:
        void splitLine( std::vector<std::string>& buff, std::stringstream& mss_line) {
            // Splits the comma separated line to vector of tokens.
            // The line is converted to string stream in the constructor.
            std::string col;
            while (std::getline(mss_line,col,',')) {
                buff.push_back(col);
            }
        }

    public:
        std::vector<std::string> buff;  // Vector buffer for the split line

        // Constructor
        CSVLine(std::string line) {
            std::stringstream mss_line; // Using getline function so need to make a stream
            mss_line.str(line);
            splitLine(buff,mss_line);
        }

};

class CSVList{
    // Read CSV file and store the split line information to a vector of CSVLine instances 
    private:
        std::vector<std::vector<std::string>> data;   // Container for the csv data. Make some getter functions for this?        

    public:

        CSVList(std::string file_name, bool contains_header){
            std::fstream csv_file(file_name,std::ios::in);
            // add error handling

            std::string line;

            // First read the header line
            if (contains_header) {
                std::getline(csv_file,line);
                // DO STUFF with the header?
            }
        
            // Read the rest of the data and store the asset information
            while (std::getline(csv_file,line)) {
                CSVLine entry(line); 
                data.push_back(entry.buff);
            }
            csv_file.close();

            
            for (int i = 0; i < data.size(); ++i ) {
                for (const auto &s : data[i]) std::cout << s << ' ';
                std::cout << std::endl;
            }
            
        }

};



int main(){

    std::string file_name = "data/listing_status.csv";
 
    CSVList assets(file_name,true);

    return 0;

}