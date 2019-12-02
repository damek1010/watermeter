#ifndef HTML_LOADER_H
#define HTML_LOADER_H

SdFat sd;

class HTMLLoader {
  public:
    String load(String filename) {
      Serial.print("Loading file: ");
      Serial.println(filename);
      
      File file = sd.open(filename);
      String content = "";
      while (file.available()) {
        content.concat((char)file.read());
      }
      file.close();

//      Serial.println(content);
      return content;
    }
};

#endif
