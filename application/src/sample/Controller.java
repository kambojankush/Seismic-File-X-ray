package sample;


import javafx.scene.control.*;

import javafx.stage.FileChooser;


import java.io.*;

public class Controller {

    public TextArea binaryHeader;
    public TextArea traceHeader;
    public TextArea EXTtrace;
    public Spinner<Integer> tracespinner;
    public Spinner<Integer> samplespinner;
    public TextArea textHeader;
    public TextArea traceSample;

    public void onDisplay() throws IOException {

        traceHeader.clear();
        String a = tracespinner.getEditor().getText();
        String b = samplespinner.getEditor().getText();
        System.out.println(a);
        FileReader data = new FileReader("D:\\Seismic File X-ray\\output\\TraceData.csv");
        FileReader header = new FileReader("C:\\Users\\Student\\IdeaProjects\\SEGY\\traceheader.csv");
        FileReader title = new FileReader("C:\\Users\\Student\\Desktop\\TraceTitle.txt");
        BufferedReader datardr = new BufferedReader(data);
        BufferedReader  titlerdr= new BufferedReader(title);
        LineNumberReader headerrdr = new LineNumberReader(header);

        String path = "D:\\Seismic File X-ray\\bin\\ReadData.exe";

        if (new File(path).exists())

        {
            try {
                ProcessBuilder pb = new ProcessBuilder(path, "D:\\Seismic File X-ray\\Dump\\PSTM_STACK_439_UTM.sgy",a,b);
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

        traceSample.appendText(datardr + "\n");

        int l = Integer.parseInt(tracespinner.getEditor().getText());


        String line, line2;
        while (headerrdr.readLine() != null) {
            if (headerrdr.getLineNumber() == l) {
                line = headerrdr.readLine().replaceAll(",", "\n");
                String[] ary = line.split("\n");
                int i = 0;
                while ((line2 = titlerdr.readLine()) != null) {
                    if (line2.isEmpty())
                        traceHeader.appendText(line2 + "\t\t\t\t" + ary[i] + "\n");
                    else
                        traceHeader.appendText(line2 + "\t\t" + ary[i] + "\n");
                    ++i;
                }
            }
        }
    }






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
                ProcessBuilder pb = new ProcessBuilder(path, opener(), "textheader.txt", "binaryheader.txt", "extendedtextheader.txt", "traceheader.csv");
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
        File reader = new File("C:\\Users\\Student\\IdeaProjects\\SEGY\\textheader.txt");
        reader.delete();
        reader = new File("C:\\Users\\Student\\IdeaProjects\\SEGY\\binaryheader.txt");
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
            FileReader reader = new FileReader("C:\\Users\\Student\\IdeaProjects\\SEGY\\textheader.txt");
            br = new BufferedReader(reader);
            String line, newLine = "\n";
            int grabber;

            while ((line = br.readLine()) != null) {

                textHeader.appendText(line);
                textHeader.appendText("\n");
            }
            reader = new FileReader("C:\\Users\\Student\\IdeaProjects\\SEGY\\binaryheader.txt");
            br = new BufferedReader(reader);


            while ((line = br.readLine()) != null) {

               binaryHeader.appendText(line+"\n");

            }






            /*reader = new FileReader("C:\\Users\\Student\\IdeaProjects\\SEGY\\extendedtextheader.txt");
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




