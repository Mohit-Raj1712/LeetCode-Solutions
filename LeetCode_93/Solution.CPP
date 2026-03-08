class Solution {
private:
    int l;
    vector<string> valid_ip_addresses;

public:
    vector<string> restoreIpAddresses(string s) {
        
        this -> l = s.length();
        vector<string> octets;

        restore_ip_addresses(s, 0, octets);

        return valid_ip_addresses;
    }

private:
    void restore_ip_addresses(string& s, int index, vector<string>& octets) {

        if (octets.size() > 4)
            return;

        if (index == l && octets.size() == 4)
        {
            string ip_address = octets[0] + "." + octets[1] + "." + octets[2] + "." + octets[3];
            valid_ip_addresses.push_back(ip_address);

            return;
        }

        for (int i = index; i < index + 3 && i < l; i++)
        {
            string octet = s.substr(index, i - index + 1);
            int octet_val = stoi(octet);

            if ( (octet_val >= 0 && octet_val <= 255) && (octet == "0" || octet[0] != '0'))
            {
                octets.push_back(octet);
                restore_ip_addresses(s, i + 1, octets);
                octets.pop_back();
            }
        }

        return;
    }
};