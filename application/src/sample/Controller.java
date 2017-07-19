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
    public Button readbutton;
    public Button Display;

    //Add paths to required files
    String path_exe = "/home/ankush/Documents/Project/Seismic File X-ray/bin/ReadHeaders";
    String path_TextHeader = "/home/ankush/Documents/Project/Seismic File X-ray/output/TextHeader.txt";
    String path_BinaryHeader = "/home/ankush/Documents/Project/Seismic File X-ray/output/BinaryHeader.txt";
    String path_ExtendedTextHeader = "/home/ankush/Documents/Project/Seismic File X-ray/output/ExtendedTextHeader.txt";
    String path_TraceHeader = "/home/ankush/Documents/Project/Seismic File X-ray/output/TraceHeader.csv";
    String path_TraceData = "/home/ankush/Documents/Project/Seismic File X-ray/output/TraceData.csv";
    String path_TraceTitle = "/home/ankush/Documents/Project/Seismic File X-ray/output/TraceTitle.txt";
    String path_exe2 = "/home/ankush/Documents/Project/Seismic File X-ray/bin/ReadData";
    String path_Segy ;
    
    public void onDisplay() throws IOException {

        traceHeader.clear();
        traceSample.clear();
        String a = tracespinner.getEditor().getText();
        String b = samplespinner.getEditor().getText();

        if (new File(path_exe2).exists())

        {
            try {
                ProcessBuilder pb = new ProcessBuilder(path_exe2, path_Segy, a, b);
                pb.redirectError();
                Process p = pb.start();
                InputStream is = p.getInputStream();
                int value = -1;
                while ((value = is.read()) != -1) {
                    System.out.print((char) value);
                }
                int exitCode = p.waitFor();

                System.out.println(path_exe2 + " EXITED WITH " + exitCode);
            } catch (IOException e) {
                e.printStackTrace();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        } else
            System.out.println(path_exe2 + " Doesn't Exists");

        FileReader data = new FileReader(path_TraceData);
        FileReader header = new FileReader(path_TraceHeader);
        FileReader title = new FileReader(path_TraceTitle);
        BufferedReader datardr = new BufferedReader(data);
        BufferedReader  titlerdr= new BufferedReader(title);
        LineNumberReader headerrdr = new LineNumberReader(header);

        traceSample.setStyle("-fx-font-family: monospace");
        traceSample.appendText(datardr.readLine().replaceAll(",", "\n"));

        int l = Integer.parseInt(tracespinner.getEditor().getText());


        String line, line2;
        while ((line = headerrdr.readLine()) != null) {
            if (headerrdr.getLineNumber() == l) {

                line = line.replaceAll(",", "\n");
                String[] ary = line.split("\n");

                traceHeader.setStyle("-fx-font-family: monospace");
                int i = 0;
                while ((line2 = titlerdr.readLine()) != null) {
                        traceHeader.appendText(line2 + ary[i] + "\n");
                        i++;
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
        if (new File(path_exe).exists())

        {
            try {
                path_Segy = opener();
                ProcessBuilder pb = new ProcessBuilder(path_exe, path_Segy, path_TextHeader, path_BinaryHeader, path_ExtendedTextHeader, path_TraceHeader);
                pb.redirectError();
                Process p = pb.start();
                InputStream is = p.getInputStream();
                int value = -1;
                while ((value = is.read()) != -1) {
                    System.out.print((char) value);
                }
                int exitCode = p.waitFor();
                System.out.println(path_exe + " EXITED WITH " + exitCode);

                readbutton.setDisable(false);
            } catch (IOException e) {
                e.printStackTrace();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        } else
            System.out.println(path_exe + " Doesn't Exists");

    }

    public void newFile() {
        File reader = new File(path_TextHeader);
        if (reader.exists()) reader.delete();
        reader = new File(path_BinaryHeader);
        if (reader.exists()) reader.delete();
        reader = new File(path_ExtendedTextHeader);
        if (reader.exists()) reader.delete();
        reader = new File(path_TraceHeader);
        if (reader.exists()) reader.delete();
        reader = new File(path_TraceData);
        if (reader.exists()) reader.delete();
        textHeader.clear();
        traceHeader.clear();
        binaryHeader.clear();
        traceSample.clear();
        EXTtrace.clear();

        execute();
    }

    public void readfile(){
        BufferedReader br;

        try {
            FileReader reader = new FileReader(path_TextHeader);
            br = new BufferedReader(reader);
            String line, newLine = "\n";
            int grabber;

            textHeader.setStyle("-fx-font-family: monospace");
            while ((line = br.readLine()) != null) {

                textHeader.appendText(line);
                textHeader.appendText("\n");
            }
            reader = new FileReader(path_BinaryHeader);
            br = new BufferedReader(reader);

            binaryHeader.setStyle("-fx-font-family: monospace");
            while ((line = br.readLine()) != null) {

                binaryHeader.appendText(line + "\n");

            }

            if (new File(path_ExtendedTextHeader).exists()) {
                reader = new FileReader(path_ExtendedTextHeader);
                br = new BufferedReader(reader);

                EXTtrace.setStyle("-fx-font-family: monospace");
                while ((line = br.readLine()) != null) {

                    EXTtrace.appendText(line + "\n");

                }
            }
            else
                EXTtrace.appendText("No Extended Textual File Header Found");

            readbutton.setDisable(true);
            Display.setDisable(false);
        }
        catch (IOException e) {
            e.printStackTrace();
        }

    }
}



