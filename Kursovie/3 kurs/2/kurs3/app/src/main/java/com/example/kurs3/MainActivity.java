package com.example.kurs3;

import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.ActivityCompat;
import androidx.core.content.ContextCompat;

import android.content.Intent;
import android.content.pm.PackageManager;
import android.graphics.Bitmap;
import android.hardware.Camera;
import android.os.Build;
import android.os.Bundle;
import android.os.Environment;
import android.util.Log;
import android.view.View;
import android.widget.ImageView;
import android.widget.Toast;

import org.openalpr.OpenALPR;

import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.text.SimpleDateFormat;
import java.util.Date;

public class MainActivity extends AppCompatActivity {
    static final String JPEG_FILE_PREFIX = "IMG_";
    static final String JPEG_FILE_SUFFIX = ".jpg";
    static String ANDROID_DATA_DIR;
    static int REQUEST_IMAGE_CAPTURE = 123;
    static String openAlprConfFile;
    public ImageView imageView;
    public OpenALPR OAInstance;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        // needs explicit permission
        super.onCreate(savedInstanceState);
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.M) {
            if (checkSelfPermission(Manifest.permission.CAMERA) != PackageManager.PERMISSION_GRANTED) {
                requestPermissions(new String[]{Manifest.permission.CAMERA}, 1);
            }
        }

        final Camera camera = Camera.open();
        CameraPreview cameraPreview = new CameraPreview(this, camera);

        // preview is required. But you can just cover it up in the layout.
        FrameLayout previewFL = findViewById(R.id.preview_layout);
        previewFL.addView(cameraPreview);
        camera.startPreview();

        // take picture button
        findViewById(R.id.take_picture_button).setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                camera.takePicture(null, null, new Camera.PictureCallback() {
                    @Override
                    public void onPictureTaken(byte[] data, Camera camera) {
                        // path of where you want to save it
                        File pictureFile = new File(getFilesDir() + "/images/pic0");

                        try {
                            FileOutputStream fos = new FileOutputStream(pictureFile);
                            fos.write(data);
                            fos.close();
                        } catch (FileNotFoundException e) {
                            e.printStackTrace();
                        } catch (IOException e) {
                            e.printStackTrace();
                        }
                    }
                });
            }
        });
    }
    public void updateView(){
        Log.i("updateView", "idk123");
        Camera camInstance = Camera.open();
        //camInstance.takePicture(shutterCallback, pictureCallback, pictureCallback2);
    }

    public Camera.ShutterCallback shutterCallback = new Camera.ShutterCallback() {
        @Override
        public void onShutter() {
            Log.i("Pic", "Pic taken");
        }
    };
    public Camera.PictureCallback pictureCallback = new Camera.PictureCallback(){
        @Override
        public void onPictureTaken(byte[] data, Camera camera){

        }
    };
    public Camera.PictureCallback pictureCallback2 = new Camera.PictureCallback(){
        @Override
        public void onPictureTaken(byte[] data, Camera camera){

        }
    };

/*
    private Camera.PictureCallback pictureCallback = new Camera.PictureCallback() {

        @Override
        public void onPictureTaken(byte[] data, Camera camera) {
            File pictureFile = getOutputMediaFile();
            if (pictureFile == null) {
                return;
            }
            try {
                FileOutputStream fos = new FileOutputStream(pictureFile);
                fos.write(data);
                fos.close();
            } catch (IOException ignored) {
            }
        }
    };

    private static File getOutputMediaFile() {
        String state = Environment.getExternalStorageState();
        if (!state.equals(Environment.MEDIA_MOUNTED)) {
            return null;
        }
        else {
            File folder_gui = new File(Environment.getExternalStorageDirectory() + File.separator + "GUI");
            if (!folder_gui.exists()) {
                folder_gui.mkdirs();
            }
            File outFile = new File(folder_gui, "temp.jpg");
            return outFile;
        }
    }


    private File createImageFile() throws IOException {
        // Create an image file name
        String timeStamp = new SimpleDateFormat("yyyyMMdd_HHmmss").format(new Date());
        String imageFileName = JPEG_FILE_PREFIX + timeStamp + "_";
        File storageDir = getStorageDir();
        File imageF = File.createTempFile(imageFileName, JPEG_FILE_SUFFIX, storageDir);
        return imageF;
    }
    private File getStorageDir(){
        File storageDir = null;
        if (Environment.MEDIA_MOUNTED.equals(Environment.getExternalStorageState())) {
            storageDir = getExternalFilesDir(null);
        } else {
            Log.v(getString(R.string.app_name), "External storage is not mounted READ/WRITE.");
        }
        return storageDir;
    }
    protected void onActivityResult(int requestCode, int resultCode, Intent data) {
        super.onActivityResult(requestCode, resultCode, data);
        if (requestCode == REQUEST_IMAGE_CAPTURE && resultCode == RESULT_OK) {
            Bundle extras = data.getExtras();
            Bitmap imageBitmap = (Bitmap) extras.get("data");
            try {
                File image = createImageFile();
                image.createNewFile();
                Bitmap bitmap = imageBitmap;
                ByteArrayOutputStream bos = new ByteArrayOutputStream();
                bitmap.compress(Bitmap.CompressFormat.PNG, 0 , bos);
                byte[] bitmapdata = bos.toByteArray();
                FileOutputStream fos = new FileOutputStream(image);
                fos.write(bitmapdata);
                fos.flush();
                fos.close();

                Toast.makeText(getApplicationContext(), OAInstance.recognize(image.getPath(), 1), Toast.LENGTH_LONG).show();
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
            imageView.setImageBitmap(imageBitmap);
        }
    }*/
}