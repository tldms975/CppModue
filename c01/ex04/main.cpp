#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

bool  file_to_string(const std::string &path, std::string &content) {
  std::ifstream     infile(path); // default std::ios_base::in
  std::stringstream ss;

  if (!infile.is_open()) {
    std::cerr << "File open error" << std::endl;
    return (false);
  }
  ss << infile.rdbuf();
  if (ss.fail()) {
    std::cerr << "File read error - infile" << std::endl;
    return (false);
  }
  infile.close();
  content = ss.str();
  return (true);
}

bool  replace(const std::string &s1, const std::string &s2, \
              const std::string &path, std::string &content) {
  std::ofstream o_file(path + ".replace"); // default std::ios_base::out | std::ios_base::trunc
  int           s1_len;
  unsigned long copy_pos;
  unsigned long replace_pos;

  if (!o_file.is_open()) {
    std::cerr << "File open error - outfile" << std::endl;
    return (false);
  }
  s1_len = s1.length();
  if (content.length() == 0 || s1_len == 0)
    return (true);
  copy_pos = 0;
  while (copy_pos != std::string::npos) {
    replace_pos = content.find(s1, copy_pos);
    if (replace_pos != std::string::npos) {
      for (unsigned long i = copy_pos; i < replace_pos; ++i)
        o_file << content[i];
      o_file << s2;
      copy_pos = replace_pos + s1_len;
    }
    else {
      while (content[copy_pos])
        o_file << content[copy_pos++];
      copy_pos = std::string::npos;
    }
  }
  o_file.close();
  return (true);
}

bool  valid_arg(std::string arg) {
  if (arg.empty())
    return (false);
  return (true);
}

int main(int ac, char *av[]) {
  std::string content;

  if (ac != 4) {
    std::cerr << "Argument error" << std::endl;
    return (1);
  }
  if (!valid_arg(av[2])) {
    std::cerr << "Invalid argument" << std::endl;
    return (1);
  }
  if (!file_to_string(av[1], content))
    return (1);
  if (replace(av[2], av[3], av[1], content))
      return (1);
  return (0);
}