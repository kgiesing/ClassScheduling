#ifndef READER_H
#define READER_H

// interface
/// class Reader -
template <Object T>
class Reader {
  // Operations
public:
  virtual T read () = 0;
};

#endif // READER_H
