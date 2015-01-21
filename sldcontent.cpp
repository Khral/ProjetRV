#include "sldcontent.h"

using namespace std;

SLDContent::SLDContent(string path)
{
    TiXmlDocument doc(path);
    if(!doc.LoadFile()){
        cerr << "erreur lors du chargement" << endl;
        cerr << "error #" << doc.ErrorId() << " : " << doc.ErrorDesc() << endl;
    }

    TiXmlHandle hdl(&doc);
    TiXmlElement *elem = hdl.FirstChildElement().FirstChildElement().Element();

}
