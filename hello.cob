        IDENTIFICATION DIVISION.
        PROGRAM-ID. hello.
        ENVIRONMENT DIVISION.
        DATA DIVISION.
        WORKING-STORAGE SECTION.
        01 C-STRING-POINTER PIC S9(9) BINARY.
        01 HELLO-WORLD.
                03 HELLO PIC X(6) VALUE "Hello ".
                03 WORLD PIC X(6) VALUE "World!".
        01 PIPE   PIC X VALUE '|'.
        01 PRINT-RESULT PIC X(150) VALUE SPACES.
        LINKAGE SECTION.
        01 LINKAGE-DATA.
                03 RESULT    PIC X(200).
        PROCEDURE DIVISION.

            DISPLAY "STARTING COBOL".

            DISPLAY "CALLING C FROM COBOL".
            CALL "say"
                USING HELLO-WORLD
                RETURNING C-STRING-POINTER.
            DISPLAY 'BACK IN COBOL AFTER CALLING C'

            DISPLAY C-STRING-POINTER.
            DISPLAY HELLO-WORLD.
      *     SET ADDRESS OF LINKAGE-DATA TO C-STRING-POINTER.            

      *      STRING 
      *          PIPE DELIMITED BY SIZE
      *          RESULT DELIMITED BY SIZE,
      *          PIPE DELIMITED BY SIZE
      *          INTO PRINT-RESULT.
            DISPLAY PRINT-RESULT.
            DISPLAY "LEAVING COBOL".
            STOP RUN.
