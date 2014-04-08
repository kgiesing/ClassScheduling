#ifndef FILEREADER_H
#define FILEREADER_H

template <class T>
class FileReader {
  // Attributes
private:
  static std::string _filename;
  // Operations
public:
  std::string getFilename ();
  setFilename (const std::string& filename);
};

#endif // FILEREADER_H
