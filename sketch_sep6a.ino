// serial_dice.ino
// Proyecto: Arduino Serial Dice
// Autor: Tierramix
// Discord: discord.gg/sRY3CRJMT8
// Licencia: MIT
// Versión: 1.3
// Nota: Si usas este código, por favor da créditos a Tierramix.

// Colores ANSI (no todos los monitores los soportan)
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

String idioma = "ES";  


void mostrarBanner() {
  Serial.println(GREEN "===========================================" RESET);
  Serial.println(CYAN  "   █████╗ ██████╗ ██╗   ██╗██╗███╗   ███╗" RESET);
  Serial.println(CYAN  "  ██╔══██╗██╔══██╗██║   ██║██║████╗ ████║" RESET);
  Serial.println(CYAN  "  ███████║██████╔╝██║   ██║██║██╔████╔██║" RESET);
  Serial.println(CYAN  "  ██╔══██║██╔═══╝ ██║   ██║██║██║╚██╔╝██║" RESET);
  Serial.println(CYAN  "  ██║  ██║██║     ╚██████╔╝██║██║ ╚═╝ ██║" RESET);
  Serial.println(CYAN  "  ╚═╝  ╚═╝╚═╝      ╚═════╝ ╚═╝╚═╝     ╚═╝" RESET);
  Serial.println(YELLOW "          🎲 Arduino Serial Dice v1.3" RESET);
  Serial.println(MAGENTA "          Autor: By Tierramix" RESET);
  Serial.println(BLUE "          Discord: discord.gg/sRY3CRJMT8" RESET);
  Serial.println(WHITE "          Licencia: MIT" RESET);
  Serial.println(RED "   * Si usas este código, por favor da creditos :)" RESET);
  Serial.println(GREEN "===========================================" RESET);
  Serial.println();
}


void setup() {
  Serial.begin(9600);
  delay(100);

  randomSeed(analogRead(A0)); // Semilla aleatoria

  mostrarBanner();

  
  Serial.println("Arduino Dice listo!");
  Serial.println("Comandos disponibles:");
  Serial.println(" - 'roll'     -> tirar el dado");
  Serial.println(" - 'credits'  -> mostrar créditos");
  Serial.println(" - 'lang EN'  -> cambiar idioma a inglés");
}


void loop() {
  if (Serial.available() > 0) {
    String input = Serial.readStringUntil('\n');
    input.trim();

    
    if (input.equalsIgnoreCase("lang ES")) {
      idioma = "ES";
      Serial.println("✅ Idioma cambiado a Español.");
    } else if (input.equalsIgnoreCase("lang EN")) {
      idioma = "EN";
      Serial.println("✅ Language changed to English.");
    }

    
    else if (input.equalsIgnoreCase("credits")) {
      mostrarBanner();
    }

    
    else if (input.equalsIgnoreCase("roll")) {
      int numero = random(1, 7);
      if (idioma == "ES") {
        Serial.print("🎲 Salió: ");
      } else {
        Serial.print("🎲 Result: ");
      }
      Serial.println(numero);
    }

    
    else if (input.length() > 0) {
      if (idioma == "ES") {
        Serial.print("Comando desconocido: ");
        Serial.println(input);
        Serial.println("Usa 'roll', 'credits' o 'lang'.");
      } else {
        Serial.print("Unknown command: ");
        Serial.println(input);
        Serial.println("Use 'roll', 'credits' or 'lang'.");
      }
    }
  }
}