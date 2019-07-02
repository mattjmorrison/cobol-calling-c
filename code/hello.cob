        IDENTIFICATION DIVISION.
        PROGRAM-ID. hello.
        ENVIRONMENT DIVISION.
        DATA DIVISION.
        WORKING-STORAGE SECTION.
        01 PYTHON-ARGS.
            03 MODULE   PIC X(7) VALUE "another".
            03 FILLER   PIC X VALUE "|".
            03 FUNC     PIC X(19) VALUE "something_different".
            03 FILLER   PIC X VALUE "|".
            03 ARGS     PIC X(100) VALUE "HERE I AM".
            03 FILLER   PIC X VALUE "|".
            03 RESPONSE PIC X(100) VALUE SPACES.
        PROCEDURE DIVISION.
            CALL "python"
                USING PYTHON-ARGS.
            DISPLAY RESPONSE.
            STOP RUN.
