#ifndef FILEWRITER_H
#define FILEWRITER_H

template <class T>
class FileWriter {
  // Attributes
private:
  static std::string _filename;
  // Operations
public:
  std::string getFilename ();
  setFilename (const std::string& filename);
};

#endif // FILEWRITER_H
