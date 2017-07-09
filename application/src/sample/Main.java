package sample;

import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;

public class Main extends Application {

    @Override
    public void start(Stage primaryStage) throws Exception{
        Parent root = FXMLLoader.load(getClass().getResource("front.fxml")); // Provide the path to fxml file.
        primaryStage.setTitle("SEGY FILE READER");
        primaryStage.setScene(new Scene(root, 1280 , 720));// Default resolution of the frontEnd
        primaryStage.show();
    }


    public static void main(String[] args) {
        launch(args);
    }
}
