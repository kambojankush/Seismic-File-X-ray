package sample;

import javafx.scene.control.Button;
import javafx.scene.control.TextArea;
import javafx.stage.FileChooser;
import java.io.*;
import java.nio.Buffer;

public class Controller {

 
    public FileReader reader; 
    public TextArea textHeader;  //Defining required FXML objects here
    public TextArea binaryHeader;
    public TextArea traceHeader;
    public TextArea EXTtrace;

    public String opener()   
    {
        FileChooser fc = new FileChooser();   //Filechooser class used to open select file screen
        File selectFile = fc.showOpenDialog(null);
        String path = null;
        if (selectFile != null) {
            path = selectFile.getAbsolutePath();
            System.out.println(path);

        } else {
            System.out.println("File not valid");
        }
        return path;
    }

    public void execute()    //Executs cpp exe file and calls opener function to get the address of Segy file, passes file names as arguments
    { 
        String path = "PATH OF CPP EXE FILE";   //Add. of exe file
        if (new File(path).exists())

        {
            try {
                ProcessBuilder pb = new ProcessBuilder(path, opener(), "outputfile1.txt", "outputfile2.txt", "extendedtextheader.txt", "traceheader.csv", "tracedata.csv");//Passing file names, address of segyFile to it.
                pb.redirectError();
                Process p = pb.start();
                InputStream is = p.getInputStream();
                int value = -1;
                while ((value = is.read()) != -1) {
                    System.out.print((char) value);
                }
                int exitCode = p.waitFor();
                System.out.println(path + " EXITED WITH " + exitCode); //Printing exit code for this process
            } catch (IOException e) {
                e.printStackTrace();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        } else
            System.out.println(path + " Doesn't Exists");

    }

    public void newFile() //Deletes the txt, csv files and clears the text on textarea 
    {
        File reader = new File("C:\\Users\\Student\\IdeaProjects\\SEGY\\outputfile1.txt");
        reader.delete();
        reader = new File("C:\\Users\\Student\\IdeaProjects\\SEGY\\outputfile2.txt");
        reader.delete();
        reader = new File("C:\\Users\\Student\\IdeaProjects\\SEGY\\extendedtextheader.txt");
        reader.delete();
        reader = new File("C:\\Users\\Student\\IdeaProjects\\SEGY\\traceheader.csv");
        reader.delete();
        textHeader.clear();
        traceHeader.clear();
        binaryHeader.clear();
        EXTtrace.clear();

        execute();  // Calling execute function again to open the Select-file screen and run the cpp exe file again
    }

    public void readfile() // Read function to read the files and displaying them on Text Area 
    {
        BufferedReader br;
        try {
            FileReader reader = new FileReader("Path of text header file");
            br = new BufferedReader(reader);
            String line, newLine = "\n";

            while ((line = br.readLine()) != null) {
                textHeader.appendText(line);
                textHeader.appendText(newLine);

            }
            reader = new FileReader("Path of Binary Header file");
            br = new BufferedReader(reader);


            while ((line = br.readLine()) != null) {
                binaryHeader.appendText(line);
                binaryHeader.appendText(newLine);

            }
            reader = new FileReader("Path of trace header file");
            br = new BufferedReader(reader);

            traceHeader.appendText( br.readLine().replaceAll(",","\n"));
            traceHeader.appendText(newLine);


            reader = new FileReader("Path of Extended Trace Header file");
            br = new BufferedReader(reader);

            while ((line = br.readLine()) != null) {
                EXTtrace.appendText(line);
                EXTtrace.appendText(newLine);

            }


            //*************Reading Trace Data***************
                /*reader = new FileReader("PATH OF TRACE DATA FILE");
                     br = new BufferedReader(reader);

                    while ((line = br.readLine()) != null) {
                        traceHeader.appendText(line);
                        traceHeader.appendText(newLine);
                 }
              */

        }

         catch (IOException e) {
            e.printStackTrace();
        }

    }
}




