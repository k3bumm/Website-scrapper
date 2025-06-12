#include <cpr/cpr.h>
#include <iostream>
#include <regex>
#include <windows.h>
using namespace std;
int main() {
    string Welche_website;
    string Was_tun; 
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h,2);

    cout << "Gebe die Website ein die gescrapt werden soll:\n";
    cin >> Welche_website;

    auto response = cpr::Get(cpr::Url{Welche_website});
    string html = response.text;

    if (response.status_code != 200) {
        cout << "Fehler beim Abrufen der Seite!" << endl;
        return 1;
    }

    cout << "Was willst du scrapen?" << endl;
    cout << "1. Links" << endl;
    cout << "2. Downloadbare Dateien" << endl;
    cout << "3. Bilder" << endl;
    cout << "Was willst du tun: ";
    cin >> Was_tun;

    if (Was_tun == "1") {
        regex link_regex("<a\\s+[^>]*href=[\"']([^\"']+)[\"'][^>]*>");
        smatch match;
        auto it = html.cbegin();
        while (regex_search(it, html.cend(), match, link_regex)) {
            cout << "Gefundener Link: " << match[1] << endl;
            it = match.suffix().first;
        }
    } else if (Was_tun == "2") {
        regex datei_regex("<a\\s+[^>]*href=[\"']([^\"']+\\.(pdf|zip|mp3|mp4|jpg|jpeg|png|docx|xlsx|pptx|exe|rar|7z|tar|gz|wav|flac|epub|mobi|txt|csv|json|xml|apk|msi|iso|svg|gif|bmp|ogg|webm|mov))([\"'])[^>]*>");
        smatch match;
        auto it = html.cbegin();
        while (regex_search(it, html.cend(), match, datei_regex)) {
            cout << "Gefundene Datei: " << match[1] << endl;
            it = match.suffix().first;
        }
    } else if (Was_tun == "3") {
        regex img_regex("<img\\s+[^>]*src=[\"']([^\"']+\\.(jpg|jpeg|png|gif|bmp|svg|webp))([\"'])[^>]*>");
        smatch match;
        auto it = html.cbegin();
        while (regex_search(it, html.cend(), match, img_regex)) {
            cout << "Gefundenes Bild: " << match[1] << endl;
            it = match.suffix().first;
        }
    } else {
        cout << "Das ist keine Anwendung. Bitte starte das Programm neu." << endl;
    }
    return 0;
}