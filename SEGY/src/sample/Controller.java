package sample;

import javafx.scene.control.Button;
import javafx.scene.control.TextArea;
import javafx.stage.FileChooser;
import java.io.*;
import java.nio.Buffer;

public class Controller {


    public FileReader reader;
    public TextArea textHeader;
    public TextArea binaryHeader;
    public TextArea traceHeader;
    public TextArea EXTtrace;

    public String opener() {
        FileChooser fc = new FileChooser();
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

    public void execute() {
        String path = "D:\\Seismic File X-ray\\src\\ReadHeaders.exe";
        if (new File(path).exists())

        {
            try {
                ProcessBuilder pb = new ProcessBuilder(path, opener(), "outputfile1.txt", "outputfile2.txt", "extendedtextheader.txt", "traceheader.csv", "tracedata.csv");
                pb.redirectError();
                Process p = pb.start();
                InputStream is = p.getInputStream();
                int value = -1;
                while ((value = is.read()) != -1) {
                    System.out.print((char) value);
                }
                int exitCode = p.waitFor();
                System.out.println(path + " EXITED WITH " + exitCode);
            } catch (IOException e) {
                e.printStackTrace();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        } else
            System.out.println(path + " Doesn't Exists");

    }

    public void newFile() {
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

        execute();
    }

    public void readfile(){
        BufferedReader br;

        try {
            FileReader reader = new FileReader("C:\\Users\\Student\\IdeaProjects\\SEGY\\outputfile1.txt");
            br = new BufferedReader(reader);
            String line, newLine = "\n";

            while ((line = br.readLine()) != null) {
                textHeader.appendText(line);
                textHeader.appendText(newLine);

            }
            reader = new FileReader("C:\\Users\\Student\\IdeaProjects\\SEGY\\outputfile2.txt");
            br = new BufferedReader(reader);


            while ((line = br.readLine()) != null) {
                binaryHeader.appendText(line);
                binaryHeader.appendText(newLine);

            }
            reader = new FileReader("C:\\Users\\Student\\IdeaProjects\\SEGY\\traceheader.csv");
            br = new BufferedReader(reader);



            traceHeader.appendText( br.readLine().replaceAll(",","\n"));
            traceHeader.appendText(newLine);


            reader = new FileReader("C:\\Users\\Student\\IdeaProjects\\SEGY\\extendedtextheader.txt");
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




