import javafx.application.Application;
import javafx.fxml.FXMLLoader;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.stage.Stage;
public class FormSample extends Application {
@Override
public void start(Stage stage) throws Exception {
stage.setTitle("Forrm Sample");
Parent root = FXMLLoader.load(getClass().getResource("Form.xml"));
Scene scene = new Scene(root);
stage.setScene(scene);
stage.show();
}
public static void main(String[] args) {
launch(args);
}
}