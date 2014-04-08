#ifndef WRITER_H
#define WRITER_H

template <Object T>
class Writer {
  // Operations
public:
  virtual setContents (T contents) = 0;
  virtual write () = 0;
};

#endif // WRITER_H
